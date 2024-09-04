
struct SDL_Window;
struct SDL_Renderer;
struct _SDL_GameController;
typedef union SDL_Event SDL_Event;
               bool ImGui_ImplSDL2_InitForOpenGL(SDL_Window* window, void* sdl_gl_context);
               bool ImGui_ImplSDL2_InitForVulkan(SDL_Window* window);
               bool ImGui_ImplSDL2_InitForD3D(SDL_Window* window);
               bool ImGui_ImplSDL2_InitForMetal(SDL_Window* window);
               bool ImGui_ImplSDL2_InitForSDLRenderer(SDL_Window* window, SDL_Renderer* renderer);
               bool ImGui_ImplSDL2_InitForOther(SDL_Window* window);
               void ImGui_ImplSDL2_Shutdown();
               void ImGui_ImplSDL2_NewFrame();
               bool ImGui_ImplSDL2_ProcessEvent(const SDL_Event* event);
enum ImGui_ImplSDL2_GamepadMode { ImGui_ImplSDL2_GamepadMode_AutoFirst, ImGui_ImplSDL2_GamepadMode_AutoAll, ImGui_ImplSDL2_GamepadMode_Manual };
               void ImGui_ImplSDL2_SetGamepadMode(ImGui_ImplSDL2_GamepadMode mode, struct _SDL_GameController** manual_gamepads_array = ((void *)0), int manual_gamepads_count = -1);