//
//  RBDViewController.m
//  RBDMuteSwitchExample
//
//  Created by Richard Hyland on 18/04/2012.
//  Copyright (c) 2012 RBDSolutions Limited. All rights reserved.
//

#import "RBDViewController.h"

@implementation RBDViewController

@synthesize muteLabel;

#pragma mark View Lifecycle methods
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self beginDetection];
    updateTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(beginDetection) userInfo:nil repeats:YES];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [updateTimer invalidate];
    updateTimer = nil;
    
    [[RBDMuteSwitch sharedInstance] setDelegate:nil];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

#pragma mark Timer methods
- (void)beginDetection {
    [[RBDMuteSwitch sharedInstance] setDelegate:self];
    [[RBDMuteSwitch sharedInstance] detectMuteSwitch];
}


#pragma mark RBDMuteSwitchDelegate methods
- (void)isMuted:(BOOL)muted {
    if (muted) {
        [muteLabel setText:@"Muted"];
    }
    else {
        [muteLabel setText:@"Not Muted"];
    }
}

@end
