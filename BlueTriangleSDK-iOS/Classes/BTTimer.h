//
//  BTTimer.h
//  BlueTriangle
//
//  Created by Julian Wilkison-Duran on 10/09/2020.
//  Copyright (c) 2020 Blue Triangle. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
    @header BTTimer
    @abstract A timer instance that can be started, marked interactive, and ended.
    @discussion Timers maintain the start, interactive, and end times in milliseconds. They also maintain a map of attributes for the timer such as page name, brand value, campaign name, AB test, etc.
 */
@interface BTTimer : NSObject

/*!
    @property running
    @abstract Determines if this timer is currently running
    @return True if timer has started but not yet ended.
 */
@property (nonatomic, readonly, getter = isRunning) BOOL running;

/*!
    @property ended
    @abstract Determines if this timer has been ended
    @return True if ended, else false
 */
@property (nonatomic, readonly, getter = hasEnded) BOOL ended;

/*!
    Create a timer instance with no page name or traffic segment name.
    @discussion NOTE - Page name or Traffic segment name will need to be set later before submitting the timer.
 */
+ (nonnull BTTimer *)timer;


/*!
    Create a timer instance with the given page name and traffic segment name
    @param pageName The page name
    @param trafficSegment The traffic segment name
 */
+ (nonnull BTTimer *)timerWithPageName:(nonnull NSString *)pageName trafficSegment:(nonnull NSString *)trafficSegment;

/*!
    Create a timer instance with the given page name, traffic segment name, optional AB test id, and optional content group name.
    @param pageName The page name
    @param trafficSegment The traffic segment name
    @param abTestIdentifier The AB test id
    @param contentGroupName The content group name
 */
+ (nonnull BTTimer *)timerWithPageName:(nonnull NSString *)pageName trafficSegment:(nonnull NSString *)trafficSegment
                      abTestIdentifier:(nullable NSString *)abTestIdentifier contentGroupName:(nullable NSString *)contentGroupName;

/*!
    Start this timer if not already started. If already started, will log an error.
 */
- (void)start;

/*!
     Mark this timer interactive at current time if the timer has been started and not already marked interactive.
     If the timer has not been started yet, log an error. If the timer has already been marked interactive, log an error.
 */
- (void)interactive;

/*!
    End this timer.
 */
- (void)end;

/*!
    Set the timer's page name
    @param pageName name of the page for this timer
 */
- (void)setPageName:(nonnull NSString *)pageName;

/*!
    Set the value of this page/timer
    @param pageValue value of page
 */
- (void)setPageValue:(double)pageValue;

/*!
    Set the timer's traffic segment name
    @param trafficSegmentName name of the traffic segment for this timer
 */
- (void)setTrafficSegmentName:(nonnull NSString *)trafficSegmentName;

/*!
    Set this timer's AB test identifier
    @param abTestIdentifier the AB test id
 */
- (void)setABTestIdentifier:(nonnull NSString *)abTestIdentifier;

/*!
    Set the content group name or page type for this timer
    @param contentGroupName name of content group or page type
 */
- (void)setContentGroupName:(nonnull NSString *)contentGroupName;

/*!
    Set the brand value of this timer
    @param brandValue brand's value
 */
- (void)setBrandValue:(double)brandValue;

/*!
    Set the value of the cart for this timer
    @param cartValue value of cart
 */
- (void)setCartValue:(double)cartValue;

/*!
    Set the order number for this timer
    @param orderNumber order number
 */
- (void)setOrderNumber:(nonnull NSString *)orderNumber;

/*!
    Set the time of the order
    @param orderTime epoch time of order in milliseconds
 */
- (void)setOrderTime:(NSInteger)orderTime;

/*!
    Set the name of the campaign
    @param campaignName name of campaign
 */
- (void)setCampaignName:(nonnull NSString *)campaignName;

/*!
    Set the source of the campaign
    @param campaignSource source of campaign
 */
- (void)setCampaignSource:(nonnull NSString *)campaignSource;

/*!
    Set the medium of the campaign
    @param campaignMedium medium of campaign
 */
- (void)setCampaignMedium:(nonnull NSString *)campaignMedium;

/*!
    Set time on page for this timer
    @param timeOnPage time on page in milliseconds
 */
- (void)setTimeOnPage:(NSInteger)timeOnPage;

/*!
    Set the URL for this timer
    @param url the url for this timer
 */
- (void)setURL:(nonnull NSString *)url;

/*!
    Set the referrer URL for this timer
    @param referrer the referrer URL
 */
- (void)setReferrer:(nonnull NSString *)referrer;

/*!
    Allows the setting of multiple fields via a Dictionary
    @param fields The fields to set on this timer
 */
- (void)setFields:(nonnull NSDictionary *)fields;

/*!
    Sets a field name with the given value
    @param fieldName The name of the field to set
    @param stringValue The value to set for the given field
 */
- (void)setField:(nonnull NSString *)fieldName stringValue:(nonnull NSString *)stringValue;

/*!
    Sets a field name with the given value
    @param fieldName The name of the field to set
    @param integerValue The value to set for the given field
 */
- (void)setField:(nonnull NSString *)fieldName integerValue:(NSInteger)integerValue;

/*!
    Sets a field name with the given value
    @param fieldName The name of the field to set
    @param floatValue The value to set for the given field
 */
- (void)setField:(nonnull NSString *)fieldName floatValue:(float)floatValue;

/*!
    Sets a field name with the given value
    @param fieldName The name of the field to set
    @param doubleValue The value to set for the given field
 */
- (void)setField:(nonnull NSString *)fieldName doubleValue:(double)doubleValue;

/*!
    Sets a field name with the given value
    @param fieldName The name of the field to set
    @param boolValue The value to set for the given field
 */
- (void)setField:(nonnull NSString *)fieldName boolValue:(BOOL)boolValue;

/*!
    Resets a field to the default value if there is one else removes the field completely.
    @param fieldName name of field to remove
 */
- (void)clearField:(nonnull NSString *)fieldName;

- (NSString *)getField:(NSString *)fieldName;

/*!
    Get all the fields currently associated with this timer.
    @return Returns a Dictionary with all the fields currently.
 */
- (nullable NSDictionary *)allFields;

@end

extern NSString * _Nullable const kLogTag;
extern NSString * _Nullable const kExtraTimer;
extern NSString * _Nullable const kPageName;
extern NSString * _Nullable const kNST;
extern NSString * _Nullable const kUnloadEventStart;
extern NSString * _Nullable const kContentGroupName;
extern NSString * _Nullable const kPageValue;
extern NSString * _Nullable const kPageTime;
extern NSString * _Nullable const kDomInteractive;
extern NSString * _Nullable const kNavigationType;
extern NSString * _Nullable const kCartValue;
extern NSString * _Nullable const kOrderNumber;
extern NSString * _Nullable const kOrderTime;
extern NSString * _Nullable const kEventType;
extern NSString * _Nullable const kSiteID;
extern NSString * _Nullable const kTrafficSegmentName;
extern NSString * _Nullable const kCampaign;
extern NSString * _Nullable const kTimeOnPage;
extern NSString * _Nullable const kBrandValue;
extern NSString * _Nullable const kURL;
extern NSString * _Nullable const kBVZN;
extern NSString * _Nullable const kOS;
extern NSString * _Nullable const kSessionID;
extern NSString * _Nullable const kGlobalUserID;
extern NSString * _Nullable const kCustomValue4;
extern NSString * _Nullable const kRV;
extern NSString * _Nullable const kWCD;
extern NSString * _Nullable const kABTestID;
extern NSString * _Nullable const kCampaignSource;
extern NSString * _Nullable const kCampaignMedium;
extern NSString * _Nullable const kCampaignName;
extern NSString * _Nullable const kDataCenter;
extern NSString * _Nullable const kReferrerURL;
