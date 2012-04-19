Prior to iOS 5 it was relatively straightforward to detect whether a device was muted by using an audio route to detect playback type.

However under iOS 5 this was changed as Apple never intended for this behaviour.  In fact Apple have stated that there is no way to obtain the positioning of the mute switch and have stated that this is not a bug but an intentional change.

However RBDMuteSwitch is a simple, small and easy to use component that takes minutes to integrate, and will even work under previous versions of iOS.

A sample project is included

To integrate:

Include RBDMuteSwitch.h, RBDMuteSwitch.m and detection.aiff to your app

Add the following to the header file where you wish to detect the mute switch

    #import "RBDMuteSwitch.h"

to your interface declaration add the RBDMuteSwitchDelegate

    @interface MainViewController : UIViewController <RBDMuteSwitchDelegate>

To your implementation you can call the detection routine

    [[RBDMuteSwitch sharedInstance] setDelegate:self];
    [[RBDMuteSwitch sharedInstance] detectMuteSwitch];

then add the isMuted: delegate method

    - (void)isMuted:(BOOL)muted {
        if (muted) {
            NSLog("Muted");
        }
        else {
            NSLog("Not Muted");
        }
    }