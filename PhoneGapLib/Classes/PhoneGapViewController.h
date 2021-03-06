/*
 * PhoneGap is available under *either* the terms of the modified BSD license *or* the
 * MIT License (2008). See http://opensource.org/licenses/alphabetical for full text.
 * 
 * Copyright (c) 2005-2010, Nitobi Software Inc.
 */


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "JSONKit.h"

@class InvokedUrlCommand;
@class Sound;
@class Contacts;
@class Console;
@class PGWhitelist;

@interface PhoneGapViewController : UIViewController <UIWebViewDelegate>
{
    UIWebView* webView;
    
    NSString* _localRoot;
    NSString* _startURL;
}

@property (nonatomic, copy) NSString* localRoot;
@property (nonatomic, copy) NSString* startURL;

@property (nonatomic, retain) 	NSArray* supportedOrientations;
@property (nonatomic, retain)	UIWebView* webView;

@property (nonatomic, readonly, retain) NSMutableDictionary* pluginObjects;
@property (nonatomic, readonly, retain) NSDictionary* pluginsMap;
@property (nonatomic, readonly, retain) NSDictionary* settings;
@property (nonatomic, readonly, retain) PGWhitelist* whitelist;

- (id)initWithLocalRoot:(NSString* )localRoot andStartURL:(NSString* )startURL;

- (NSString*) pathForResource:(NSString*)resourcepath;

+ (NSDictionary*)getBundlePlist:(NSString *)plistName;
+ (NSString*) applicationDocumentsDirectory;
+ (NSString*) phoneGapVersion;

- (int)executeQueuedCommands;
- (void)flushCommandQueue;

- (id) getCommandInstance:(NSString*)pluginName;
- (void) javascriptAlert:(NSString*)text;
- (BOOL) execute:(InvokedUrlCommand*)command;
- (NSString*) appURLScheme;
- (NSDictionary*) deviceProperties;

- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)javascript;

@end


@interface NSDictionary (LowercaseKeys)

- (NSDictionary*) dictionaryWithLowercaseKeys;

@end
