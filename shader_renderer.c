#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Shader Renderer");

    // Load the shader
    Shader shader = LoadShader(0, "shader.glsl");
    if (shader.id == 0) {
        // Handle shader loading error
        CloseWindow();
        return -1;
    }

    // Set up a fullscreen render texture
    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

    SetTargetFPS(60); // Set the target frames-per-second

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Begin drawing to the render texture
        BeginTextureMode(target);
        ClearBackground(RAYWHITE);

        // Use the shader
        BeginShaderMode(shader);
        DrawRectangle(0, 0, screenWidth, screenHeight, WHITE); // Draw a rectangle to apply the shader
        EndShaderMode();

        EndTextureMode();

        // Draw the render texture to the screen
        DrawTexture(target.texture, 0, 0, WHITE);

        EndDrawing();
    }

    // Cleanup
    UnloadShader(shader);
    UnloadRenderTexture(target);
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

