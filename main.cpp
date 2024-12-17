#define THREADED

#include <vector>
#include <thread>

#include "raylib.h"

static float progress;
static std::vector<Texture2D> textures;

const float progressInc = 1.0f / 54.0f;

static void loadTexture(const char* filename)
{
    auto texture = LoadTexture(filename);
    textures.push_back(texture);
    progress += progressInc;
}

static void loadTextures()
{
    // CLUBS
    loadTexture("assets/clubs/a_clubs.png");
    loadTexture("assets/clubs/2_clubs.png");
    loadTexture("assets/clubs/3_clubs.png");
    loadTexture("assets/clubs/4_clubs.png");
    loadTexture("assets/clubs/5_clubs.png");
    loadTexture("assets/clubs/6_clubs.png");
    loadTexture("assets/clubs/7_clubs.png");
    loadTexture("assets/clubs/8_clubs.png");
    loadTexture("assets/clubs/9_clubs.png");
    loadTexture("assets/clubs/10_clubs.png");
    loadTexture("assets/clubs/j_clubs.png");
    loadTexture("assets/clubs/q_clubs.png");
    loadTexture("assets/clubs/k_clubs.png");

    // DIAMONDS
    loadTexture("assets/diamonds/a_diamonds.png");
    loadTexture("assets/diamonds/2_diamonds.png");
    loadTexture("assets/diamonds/3_diamonds.png");
    loadTexture("assets/diamonds/4_diamonds.png");
    loadTexture("assets/diamonds/5_diamonds.png");
    loadTexture("assets/diamonds/6_diamonds.png");
    loadTexture("assets/diamonds/7_diamonds.png");
    loadTexture("assets/diamonds/8_diamonds.png");
    loadTexture("assets/diamonds/9_diamonds.png");
    loadTexture("assets/diamonds/10_diamonds.png");
    loadTexture("assets/diamonds/j_diamonds.png");
    loadTexture("assets/diamonds/q_diamonds.png");
    loadTexture("assets/diamonds/k_diamonds.png");

    // HEARTS
    loadTexture("assets/hearts/A_hearts.png");
    loadTexture("assets/hearts/2_hearts.png");
    loadTexture("assets/hearts/3_hearts.png");
    loadTexture("assets/hearts/4_hearts.png");
    loadTexture("assets/hearts/5_hearts.png");
    loadTexture("assets/hearts/6_hearts.png");
    loadTexture("assets/hearts/7_hearts.png");
    loadTexture("assets/hearts/8_hearts.png");
    loadTexture("assets/hearts/9_hearts.png");
    loadTexture("assets/hearts/10_hearts.png");
    loadTexture("assets/hearts/J_hearts.png");
    loadTexture("assets/hearts/Q_hearts.png");
    loadTexture("assets/hearts/K_hearts.png");

    // SPADES
    loadTexture("assets/spades/a_spades.png");
    loadTexture("assets/spades/2_spades.png");
    loadTexture("assets/spades/3_spades.png");
    loadTexture("assets/spades/4_spades.png");
    loadTexture("assets/spades/5_spades.png");
    loadTexture("assets/spades/6_spades.png");
    loadTexture("assets/spades/7_spades.png");
    loadTexture("assets/spades/8_spades.png");
    loadTexture("assets/spades/9_spades.png");
    loadTexture("assets/spades/10_spades.png");
    loadTexture("assets/spades/j_spades.png");
    loadTexture("assets/spades/q_spades.png");
    loadTexture("assets/spades/k_spades.png");
}

int main(void)
{
    progress = 0.0f;

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib multithreaded");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

#ifdef THREADED
    std::thread loading(loadTextures);
#else
    loadTextures();
#endif

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Progress loading textures", 190, 200, 20, LIGHTGRAY);

        float barSize = progress * 300;

        DrawRectangle(190, 300, (int)barSize , 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

#ifdef THREADED
    loading.join();
#endif

	return 0;
}