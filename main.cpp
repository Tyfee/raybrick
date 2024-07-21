#include "raylib.h"
#include "iostream"
#include "vector"
#define MAX_BRICKS_ROW 10

//minimal brick destroying game, code by Ty (https://github.com/Tyfee).
// background image from https://freepik.com



std::vector row = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector row1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector row2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector row3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

char* bricks[] = {

};

int main(void){
    Color player_color = BLUE;
    int current_screen = 0;

    int current_option = 0;
    int score = 0;
    int player_x = 500;
    int ball_x = 500;
    int ball_y = 100;
    float speed = 8.0;
    float ball_speed = 10.0;
    float inclination = 0;
    // 0 = ascending, 1 = descending
    bool direction = 0;
    InitWindow(GetScreenWidth(), GetScreenHeight(), "RayBrick");
    InitAudioDevice();
    Texture bg = LoadTexture("assets/91657.png");
    Texture bg_music_cover = LoadTexture("assets/sonderland.png");
    Sound bg_music = LoadSound("assets/audio/sonderland.wav");
    PlaySound(bg_music);
    SetTargetFPS(60);  
    ToggleBorderlessWindowed();
    while (!WindowShouldClose())
    {

//main menu

if (current_screen == 0){
  
//key events for main menu

//up and down controls
if(IsKeyDown(KEY_DOWN) && current_option < 1) current_option += 1;
if(IsKeyDown(KEY_UP) && current_option > 0) current_option -= 1;


//key enter events
if(IsKeyDown(KEY_ENTER) && current_option == 0) current_screen = 1;
if(IsKeyDown(KEY_ENTER) && current_option == 1) WindowShouldClose();

   BeginDrawing();
        ClearBackground(BLACK);
      DrawTextureEx(bg, (Vector2){55, 0}, 0, 0.25, WHITE);
      DrawText("RAYBRICK", GetScreenWidth() / 3, GetScreenHeight() / 5, GetScreenWidth() / 15, WHITE);
 
 if(current_option == 0){
  DrawText("PLAY", GetScreenWidth() / 2, GetScreenHeight() / 3, GetScreenWidth() / 20, YELLOW);
   DrawText("EXIT", GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth() / 20, WHITE);
 }else{
  DrawText("PLAY", GetScreenWidth() / 2, GetScreenHeight() / 3, GetScreenWidth() / 20, WHITE);
   DrawText("EXIT", GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth() / 20, YELLOW);
 }
 DrawTextureEx(bg_music_cover, (Vector2){100, GetScreenHeight() - 100}, 0, 0.10, WHITE);
      DrawText("sonderland", 200, GetScreenHeight() - 100, GetScreenWidth() / 30, GRAY);
 DrawText("0xa", 200, GetScreenHeight() - 50, GetScreenWidth() / 40, GRAY);

      EndDrawing();
}


// actual game
      if (current_screen == 1){

        if(IsSoundPlaying(bg_music)){
          StopSound(bg_music);
        }
              CloseAudioDevice();
             ball_x += inclination;
        if(direction == 0){
            ball_y += ball_speed;
        }

        if(direction == 1){
            ball_y -= ball_speed;
        }
        BeginDrawing();
        ClearBackground(BLACK);
      DrawTextureEx(bg, (Vector2){55, 0}, 0, 0.25, WHITE);
      //bricks 

for(int i = 0; i < size(row); i++){
    DrawRectangle(100 + (i * 110), 0, 100, 50, YELLOW);
    DrawRectangleLines(100 + (i * 110), 0, 100, 50, WHITE);
}

for(int i = 0; i < size(row1); i++){
    DrawRectangle(100 + (i * 110), 60, 100, 50, RED);
    DrawRectangleLines(100 + (i * 110), 60, 100, 50, WHITE);
}
for(int i = 0; i < size(row2); i++){
    DrawRectangle(100 + (i * 110), 120, 100, 50, GREEN);
    DrawRectangleLines(100 + (i * 110), 120, 100, 50, WHITE);
}
for(int i = 0; i < size(row3); i++){
    DrawRectangle(100 + (i * 110), 180, 100, 50, ORANGE);
    DrawRectangleLines(100 + (i * 110), 180, 100, 50, WHITE);


}

//points
DrawRectangle(0, 0, 50, 100, BLACK);
DrawText(TextFormat("%d", score), 25, 0, GetScreenWidth() / 30, WHITE);

        //player
        Rectangle player = {player_x, GetScreenHeight() - 20, GetScreenWidth() / 5, 200};
       DrawRectangle(player_x, player.y, player.width, player.height, player_color);

       //ball
       DrawCircleGradient(ball_x, ball_y, GetScreenHeight() / 20, PINK, PURPLE);
      Rectangle ball = {ball_x, ball_y,GetScreenHeight() / 20, GetScreenHeight() / 20};
   DrawRectangleLines(ball.x, ball.y, ball.width, ball.height, WHITE);

      //detect ball/player collision, invert direction and increase ball speed
      bool collision = CheckCollisionRecs(player, ball);
      if(collision){
        ball_speed = ball_speed * 2;
         direction = 1;
         // change the ball inclination, based on what part of the player board hit the ball
        inclination = (GetScreenWidth() / player.width) - player_x / 50;
      }

      //if ball hits any corner,invert direction and reset speed
      if(ball_y < 1){
        ball_speed = 10.0;
        direction = 0;
      }
       if(ball_y > player.y ){
        ball_speed = 10.0;
        direction = 1;
      }
      //left boundary
      if(ball_x < 50){
        ball_speed = 10.0;
      
  inclination = 5;

      }
      //right boundary
      if(ball_x > GetScreenHeight() * 1.7){
        inclination = -5;
        ball_speed = 10.0;
       
      }


   EndDrawing();
   if(IsKeyDown(KEY_RIGHT)){
     player_x += speed;
   }
      
   if(IsKeyDown(KEY_LEFT)){
     player_x -= speed;
   }

      }
    }
    UnloadTexture(bg);
    UnloadTexture(bg_music_cover);
    UnloadSound(bg_music);
    
    CloseWindow();
    return 0;
}