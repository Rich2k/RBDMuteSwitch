//
//  RBDViewController.h
//  RBDMuteSwitchExample
//
//  Created by Richard Hyland on 18/04/2012.
//  Copyright (c) 2012 RBDSolutions Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RBDMuteSwitch.h"

@interface RBDViewController : UIViewController <RBDMuteSwitchDelegate> { 
    NSTimer* updateTimer;
}

@property (nonatomic, retain) IBOutlet UILabel *muteLabel;

- (void)beginDetection;
@end
