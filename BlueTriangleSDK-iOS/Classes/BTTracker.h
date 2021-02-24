//
//  BTTracker.h
//  BlueTriangle
//
//  Created by Julian Wilkison-Duran on 10/09/2020.
//  Copyright (c) 2020 Blue Triangle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sys/utsname.h>

@class BTTimer;

/*!
    @header BTTracker
    @abstract An object responsible for submitting BTTimer instances to Blue Triangle for processing.
 */
@interface BTTracker : NSObject

/*!
    Singleton instance of the tracker
 */
+ (instancetype)sharedTracker;

/*!
    Submits a timer to Blue triangle for processing
    @param timer The BTTimer instance which represents a tracked session.
 */
- (void)submitTimer:(BTTimer *)timer;

/*!
    Set the session ID for this tracker
 */
- (void)setSessionID:(NSString *)sessionID;

/*!
    Set the global user ID for this tracker
 */
- (void)setGlobalUserID:(NSString *)globalUserID;

/*!
    Set the Site ID for this tracker
 */
- (void)setSiteID:(NSString *)siteID;

/*!
    Set a global field to be applied to all trackers
 */
- (void)setGlobalField:(NSString *)fieldName stringValue:(NSString *)stringValue;

/*!
    Set a global field to be applied to all trackers
 */
- (void)setGlobalField:(NSString *)fieldName integerValue:(NSInteger)integerValue;

/*!
    Set a global field to be applied to all trackers
 */
- (void)setGlobalField:(NSString *)fieldName floatValue:(float)floatValue;

/*!
    Set a global field to be applied to all trackers
 */
- (void)setGlobalField:(NSString *)fieldName doubleValue:(double)doubleValue;

/*!
    Set a global field to be applied to all trackers
 */
- (void)setGlobalField:(NSString *)fieldName boolValue:(BOOL)boolValue;

/*!
    Set a global field to be applied to all trackers
 */
- (void)clearGlobalField:(NSString *)fieldName;

/*!
    raise a test exception 
 */
- (void)raiseTestException:(NSString *)message;

- (void)trackCrashes;

- (NSString*) deviceName;

/*!
 Get all the fields currently associated with this timer.
 @return Returns a Dictionary with all the fields currently.
 */
- (NSDictionary *)allGlobalFields;

@end

extern NSString * _Nullable globalSiteID;
extern NSString * _Nullable globalSessionID;
extern NSString * _Nullable globalDeviceName;
extern NSString * _Nullable globalGUID;
