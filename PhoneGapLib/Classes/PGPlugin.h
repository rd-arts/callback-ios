/*
 * PhoneGap is available under *either* the terms of the modified BSD license *or* the
 * MIT License (2008). See http://opensource.org/licenses/alphabetical for full text.
 * 
 * Created by Michael Nachbaur on 13/04/09.
 * Copyright (c) 2009 Decaf Ninja Software. All rights reserved.
 * Copyright (c) 2005-2010, Nitobi Software Inc.
 * Copyright (c) 2010, IBM Corporation
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PluginResult.h"
#import "NSMutableArray+QueueAdditions.h"

#define PGPluginHandleOpenURLNotification	@"PGPluginHandleOpenURLNotification"

#define VERIFY_ARGUMENTS(args, expectedCount, callbackId) if (![self verifyArguments:args withExpectedCount:expectedCount andCallbackId:callbackId \
callerFileName:__FILE__ callerFunctionName:__PRETTY_FUNCTION__]) { return; }


@class PhoneGapViewController;

@interface PGPlugin : NSObject {
    PhoneGapViewController* _viewController;
}

@property (nonatomic, retain, readonly) PhoneGapViewController* viewController;
@property (nonatomic, retain) UIWebView *webView;
@property (nonatomic, retain) NSDictionary *settings;

- (PGPlugin*) initWithViewController:(PhoneGapViewController* )viewController webView:(UIWebView*)theWebView settings:(NSDictionary*)classSettings;
- (PGPlugin*) initWithViewController:(PhoneGapViewController* )viewController webView:(UIWebView*)theWebView;

- (void) handleOpenURL:(NSNotification*)notification;
- (void) onAppTerminate;
- (void) onMemoryWarning;

/*
 // see initWithWebView implementation
 - (void) onPause {}
 - (void) onResume {}
 - (void) onOrientationWillChange {}
 - (void) onOrientationDidChange {}
 */

- (NSString*) writeJavascript:(NSString*)javascript;
- (NSString*) success:(PluginResult*)pluginResult callbackId:(NSString*)callbackId;
- (NSString*) error:(PluginResult*)pluginResult callbackId:(NSString*)callbackId;

- (BOOL) verifyArguments:(NSMutableArray*)arguments withExpectedCount:(NSUInteger)expectedCount andCallbackId:(NSString*)callbackId 
		  callerFileName:(const char*)callerFileName callerFunctionName:(const char*)callerFunctionName;

@end
