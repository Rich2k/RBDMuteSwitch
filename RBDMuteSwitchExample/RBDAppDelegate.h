//
//  RBDAppDelegate.h
//  RBDMuteSwitchExample
//
//  Created by Richard Hyland on 18/04/2012.
//  Copyright (c) 2012 RBDSolutions Limited. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RBDViewController;

@interface RBDAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) RBDViewController *viewController;

@end
