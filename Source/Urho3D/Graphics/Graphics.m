#include <SDL/SDL.h>
#include <SDL/SDL_syswm.h>
#ifdef __APPLE__
 #if defined(SDL_VIDEO_DRIVER_COCOA)
    #include <Cocoa/Cocoa.h>  // Add this import for NSWindow constants
 #endif
#endif

// Forward declaration of our observer class
@interface WindowOrderObserver : NSObject
{
    NSMutableArray *windowsToKeepOnTop; // Stores SDL_Window* as NSValue
    NSMutableArray *windowLevels;       // Stores levels as NSNumber
}
- (id)init;
- (void)windowDidChangeOrder:(NSNotification *)notification;
- (void)addWindow:(SDL_Window*)window withLevel:(int)level;
- (void)removeWindow:(SDL_Window*)window;
@end

// Implementation of our observer
@implementation WindowOrderObserver

- (id)init
{
    self = [super init];
    if (self) {
        windowsToKeepOnTop = [[NSMutableArray alloc] init];
        windowLevels = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)windowDidChangeOrder:(NSNotification *)notification
{
    // Reorder all our tracked windows
    for (NSUInteger i = 0; i < [windowsToKeepOnTop count]; i++) {
        SDL_Window *window = [(NSValue *)[windowsToKeepOnTop objectAtIndex:i] pointerValue];
        int level = [(NSNumber *)[windowLevels objectAtIndex:i] intValue];
        
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        if (SDL_GetWindowWMInfo(window, &wmInfo)) {
            NSWindow *nswindow = wmInfo.info.cocoa.window;
            [nswindow setLevel:level];
            [nswindow orderFrontRegardless];
        }
    }
}

- (void)addWindow:(SDL_Window*)window withLevel:(int)level
{
    [windowsToKeepOnTop addObject:[NSValue valueWithPointer:window]];
    [windowLevels addObject:[NSNumber numberWithInt:level]];
}

- (void)removeWindow:(SDL_Window*)window
{
    for (NSUInteger i = 0; i < [windowsToKeepOnTop count]; i++) {
        SDL_Window *storedWindow = [(NSValue *)[windowsToKeepOnTop objectAtIndex:i] pointerValue];
        if (storedWindow == window) {
            [windowsToKeepOnTop removeObjectAtIndex:i];
            [windowLevels removeObjectAtIndex:i];
            break;
        }
    }
}

@end

// Static observer instance
static WindowOrderObserver *orderObserver = nil;

// Initialize window order observer
void InitWindowOrderObserver()
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    if (!orderObserver) {
        orderObserver = [[WindowOrderObserver alloc] init];
        
        // Register for notifications about window ordering changes
        NSNotificationCenter* center = [NSNotificationCenter defaultCenter];
        [center addObserver:orderObserver 
                   selector:@selector(windowDidChangeOrder:) 
                       name:NSWindowDidBecomeKeyNotification 
                     object:nil];
        [center addObserver:orderObserver 
                   selector:@selector(windowDidChangeOrder:) 
                       name:NSWindowDidResignKeyNotification 
                     object:nil];
        [center addObserver:orderObserver 
                   selector:@selector(windowDidChangeOrder:) 
                       name:NSWindowDidMiniaturizeNotification 
                     object:nil];
        [center addObserver:orderObserver 
                   selector:@selector(windowDidChangeOrder:) 
                       name:NSWindowDidDeminiaturizeNotification 
                     object:nil];
    }
#endif
}

// Make a window persistently stay on top (even when losing focus)
void MacOSMakeWindowStayOnTop(SDL_Window* sdl_window, int priority)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    // Initialize observer system if needed
    InitWindowOrderObserver();
    
    // Set the window's level and order it front initially
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo(sdl_window, &wmInfo)) {
        NSWindow *nswindow = wmInfo.info.cocoa.window;
        [nswindow setLevel:priority];
        [nswindow orderFrontRegardless];
        
        // Add to tracking list
        [orderObserver addWindow:sdl_window withLevel:priority];
    }
#endif
}

// Stop keeping a window on top
void MacOSStopKeepingWindowOnTop(SDL_Window* sdl_window)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    if (orderObserver) {
        [orderObserver removeWindow:sdl_window];
    }
#endif
}

void MacOSSetWindowsPriority(SDL_Window* sdl_window,int priority)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(sdl_window, &wmInfo);
    
    NSWindow *nswindow = wmInfo.info.cocoa.window;
    [nswindow setLevel:priority];

    [nswindow orderFrontRegardless];

#endif
}

// New function to specifically set window to front
void MacOSSetWindowToFront(SDL_Window* sdl_window)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    SDL_GetWindowWMInfo(sdl_window, &wmInfo);
    
    NSWindow *nswindow = wmInfo.info.cocoa.window;
    // Use a very high level to ensure it's above other windows
    [nswindow setLevel:10000];
    // Additionally, order it to the front
    [nswindow orderFrontRegardless];
    // Make it the key window to receive input
    // [nswindow makeKeyAndOrderFront:nil];
#endif
}

int MacOSGetWindowLevel(SDL_Window* sdl_window)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo(sdl_window, &wmInfo)) {
        NSWindow *nswindow = wmInfo.info.cocoa.window;
        if (nswindow != nil) {
            return (int)[nswindow level];
        }
    }
    return 0; // Default level if window info can't be retrieved
#else
    // Not on macOS/Cocoa, return default level
    return 0;
#endif
}


// Function to get the global window ID
int MacOSGetGlobalWindowID(SDL_Window* sdl_window)
{
#if defined(SDL_VIDEO_DRIVER_COCOA)
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (SDL_GetWindowWMInfo(sdl_window, &wmInfo)) {
        NSWindow *nswindow = wmInfo.info.cocoa.window;
        if (nswindow != nil) {
            return (int)[nswindow windowNumber];
        }
    }
    return 0; // Invalid window number if window info can't be retrieved
#else
    // Not on macOS/Cocoa
    return 0;
#endif
}
