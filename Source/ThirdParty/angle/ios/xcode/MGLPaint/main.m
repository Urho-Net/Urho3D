//
//  main.m
//  MGLPaint
//
//  Created by Le Quyen on 17/10/19.
//  Copyright © 2019 HQGame. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char *argv[])
{
    NSString *appDelegateClassName;
    @autoreleasepool
    {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
