//
//  RBDMuteSwitch.h
//  RBDMuteSwitchExample
//
//  Created by Richard Hyland on 18/04/2012.
//  Copyright (c) 2012 RBDSolutions Limited. All rights reserved.
//

/** This class detects whether the device is muted including under iOS 5.
    You should use the sharedInstance to get an instance and implement the isMuted: delegate method.
 
    Example
   [[RBDMuteSwitch sharedInstance] setDelegate:self];
   [[RBDMuteSwitch sharedInstance] detectMuteSwitch];
 
   - (void)isMuted:(BOOL)muted { 
   }
 */

#import <Foundation/Foundation.h>
#include <AudioToolbox/AudioToolbox.h>

@class RBDMuteSwitch;

@protocol RBDMuteSwitchDelegate
    @required
    - (void)isMuted:(BOOL)muted;
@end

@interface RBDMuteSwitch : NSObject {
    @private
    NSObject<RBDMuteSwitchDelegate> *delegate;
    float soundDuration;
    NSTimer *playbackTimer;
}

/**
 Your delegate
 */
@property (readwrite, retain) NSObject<RBDMuteSwitchDelegate> *delegate;

/** Creates a shared instance
 */ 
+ (RBDMuteSwitch *)sharedInstance;

/** Determines if the device is muted, wait for delegate callback using isMuted: on your delegate.
 */ 
- (void)detectMuteSwitch;

@end
