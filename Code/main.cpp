#include "Common_Function.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "ExplosionObject.h"
#include "PlayerPower.h"
#include "TextObject.h"
#include "MakeMenu.h"

using namespace std;
TTF_Font* g_font_text = NULL;




bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Show window
            SDL_ShowWindow(window);

            //Create renderer
            renderer = SDL_CreateRenderer(window, -1, 0);
        }
    }
    IMG_Init(IMG_INIT_PNG);
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        success = false;
    }
    if (TTF_Init() == -1)
    {
        return false;
    }

    //Read file load ttf
    g_font_text = TTF_OpenFont("Font_game.ttf", 50);

    //Read file load mp3
    g_sound_bullet[0] = Mix_LoadMUS("laser_sound_.mp3");
    g_sound_bullet[1] = Mix_LoadMUS("round_sound.mp3");
    g_sound_exp[0] = Mix_LoadMUS("exp_sound_.mp3");


    return success;
}



void Run_game()
{
    //Value of Bkg
    int bkg_x = 0;
    bool is_run_screen = true;

    
    //Background
    BaseObject Bkg;
    Bkg.LoadImg("Back_ground_.png", renderer);
    Bkg.SetRect_w_h(WIDTH_BKG, HEIGHT_BKG);
    Bkg.Render(renderer);

    //Make Player Power
    PlayerPower player_power;
    player_power.Init(renderer);
    player_power.SetRect_w_h(30, 30);

    //Make text in game
    TextObject mark_game;
    mark_game.SetColor(TextObject::WHITE_TEXT);
    TextObject time_play_game;
    time_play_game.SetColor(TextObject::RED_TEXT);


    //Plane main object
    MainObject Plane_main;
    Plane_main.LoadImg("Plane_main_.png", renderer);
    Plane_main.Render(renderer);
    Plane_main.SetRect_x_y(SCREEN_WIDTH / 2 - 400, SCREEN_HEIGHT / 2);
    Plane_main.SetRect_w_h(WIDTH_MAIN_OBJECT, HEIGHT_MAIN_OBJECT);

    //Explosion Object
    ExplosionObject exp_main;
    bool ret = exp_main.LoadImg("exp.png", renderer);
    exp_main.SetRect_w_h(WIDTH_EXP, HEIGHT_EXP);
    exp_main.set_clip();
    if (ret == false) {
        return ;
    }




    //Plane threat object
    ThreatObject* p_threats = new ThreatObject[NUM_THREATS];
    for (int j = 0; j < NUM_THREATS; j++)
    {
        ThreatObject* p_threat = (p_threats + j);
        p_threat->LoadImg("Plane_threat_.png", renderer);

        int rand_y = rand() % (SCREEN_HEIGHT - 5);

        p_threat->SetRect_x_y(SCREEN_WIDTH + j * 400, rand_y);
        p_threat->set_x_val(1);

        BulletObject* p_bullet = new BulletObject();
        p_threat->InitBullet(p_bullet);
    }

    Uint32 time_line;
    int die_number = 3;
    int mark_value = 0;
    bool is_quit = false;

    //Make menu game
    MakeMenu Menu;
    int ret_menu = Menu.ShowMenu(renderer, g_font_text);
    if (ret_menu)
    {
        is_quit = true;
    }


    while (!is_quit)
    {
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderClear(renderer);


        //Run Screen
        if (is_run_screen)
        {
            bkg_x -= 1;
            if (bkg_x <= -(WIDTH_BKG - SCREEN_WIDTH))
            {
                is_run_screen = false;
            }
            else
            {
                Bkg.SetRect_x_y(bkg_x, 0);
                Bkg.Render(renderer);
            }
        }
        else {
            Bkg.SetRect_x_y(bkg_x, 0);
            Bkg.Render(renderer);
        }


        //
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            Plane_main.HandleInputAction(event, g_sound_bullet);
        }

        //Show Player
        player_power.RenderPos(renderer);


        //Show Plane main
        Plane_main.HandleMove();
        Plane_main.Render(renderer);
        Plane_main.MakeBullets(renderer);


        //Make plane threat
        for (int x = 0; x < NUM_THREATS; x++)
        {
            ThreatObject* p_threat = (p_threats + x);

            if (p_threat)
            {
                p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                p_threat->Render(renderer);
                p_threat->MakeBullet(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


                //Collision main and bullet threat
                bool is_col1 = false;
                vector<BulletObject*> bullet_p = p_threat->GetBulletList();
                for (int am = 0; am < bullet_p.size(); am++)
                {
                    BulletObject* p_bullet = bullet_p.at(am);
                    if (p_bullet)
                    {
                        is_col1 = Plane_main.CheckCollision(Plane_main.GetRect(), p_bullet->GetRect());
                        if (is_col1)
                        {
                            p_threat->Resetbullet(p_bullet);
                            break;
                        }
                    }
                }


                //Check collision main and threat
                bool is_col = Plane_main.CheckCollision(Plane_main.GetRect(), p_threat->GetRect());
                if (is_col || is_col1)
                {

                    for (int ex = 0; ex < 4; ex++)
                    {
                        int x_pos = (Plane_main.GetRect().x + Plane_main.GetRect().w);
                        int y_pos = (Plane_main.GetRect().y + Plane_main.GetRect().h);

                        exp_main.set_frame(ex);
                        exp_main.SetRect_x_y(x_pos, y_pos);
                        exp_main.ShowExp(renderer);
                        SDL_Delay(100);
                        SDL_RenderPresent(renderer);
                    }

                    die_number--;
                    Mix_PlayMusic(g_sound_exp[0], 0);
                    if (die_number == 0)
                    {
                        int ret_menu = Menu.ShowMenu_end(renderer, g_font_text);
                        if (ret_menu) {
                            time_line = 0;
                            Run_game();
                        }
                        else
                        {
                            delete[] p_threats;

                            //CleanUp
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            IMG_Quit();
                            SDL_Quit();
                            TTF_Quit();
                            return ;
                        }
                    }
                    else
                    {
                        SDL_Delay(200);
                        Plane_main.SetRect_x_y(SCREEN_WIDTH / 2 - 400, SCREEN_HEIGHT / 2);
                        player_power.Decrease();
                        player_power.RenderPos(renderer);
                    }

                }

                //Check collision bullet main and threat
                vector<BulletObject*> bullet_list = Plane_main.GetBulletList();
                for (int xx = 0; xx < bullet_list.size(); xx++)
                {
                    BulletObject* p_bullets = bullet_list.at(xx);
                    if (p_bullets != NULL)
                    {
                        bool ret_col = Plane_main.CheckCollision(p_bullets->GetRect(), p_threat->GetRect());
                        if (ret_col)
                        {
                            mark_value++;
                            p_threat->Reset(SCREEN_WIDTH + x * 400);
                            Plane_main.RemoveThreat(xx);
                            Mix_PlayMusic(g_sound_exp[0], 0);
                        }
                    }
                }

            }
        }
        //Show mark value
        string val_str_mark = to_string(mark_value);
        string str_mark("Mark: ");
        str_mark += val_str_mark;
        mark_game.SetText(str_mark);
        mark_game.SetRect_x_y(500, 10);
        mark_game.SetRect_w_h(50, 20);
        mark_game.CreateGameText(g_font_text, renderer);

       
        //Show time game
        string str_time("Time: ");
        time_line = SDL_GetTicks() / 1000;
        string val_str_time = to_string(time_line);
        str_time += val_str_time;
        time_play_game.SetText(str_time);
        time_play_game.SetRect_w_h(50, 20);
        time_play_game.SetRect_x_y(SCREEN_WIDTH - 100, 20);
        time_play_game.CreateGameText(g_font_text, renderer);



        // Update the screen
        SDL_RenderPresent(renderer);
        Sleep(4);
    }
    delete[] p_threats;

}


int main(int arc, char* argv[])
{
    //
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    Run_game();

    //CleanUp
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    return 0;
}