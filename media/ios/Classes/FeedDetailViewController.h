//
//  FeedDetailViewController.h
//  NewsBlur
//
//  Created by Samuel Clay on 6/20/10.
//  Copyright 2010 NewsBlur. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ASIHTTPRequest.h"
#import "BaseViewController.h"
#import "Utilities.h"

@class NewsBlurAppDelegate;
@class FeedDetailTableCell;

@interface FeedDetailViewController : BaseViewController 
<UITableViewDelegate, UITableViewDataSource, 
 UIActionSheetDelegate, UIAlertViewDelegate,
 UIPopoverControllerDelegate, ASIHTTPRequestDelegate> {
    NewsBlurAppDelegate *appDelegate;
    
    NSArray * stories;
    int feedPage;
    BOOL pageFetching;
    BOOL pageFinished;
               
    UITableView * storyTitlesTable;
    UIToolbar * feedViewToolbar;
    UISlider * feedScoreSlider;
    UIBarButtonItem * feedMarkReadButton;
    UISegmentedControl * intelligenceControl;
    UIPopoverController *popoverController;
}

@property (nonatomic) IBOutlet NewsBlurAppDelegate *appDelegate;
@property (nonatomic) UIPopoverController *popoverController;
@property (nonatomic, strong) IBOutlet UITableView *storyTitlesTable;
@property (nonatomic) IBOutlet UIToolbar *feedViewToolbar;
@property (nonatomic) IBOutlet UISlider * feedScoreSlider;
@property (nonatomic) IBOutlet UIBarButtonItem * feedMarkReadButton;
@property (nonatomic) IBOutlet UIBarButtonItem * settingsButton;
@property (nonatomic) IBOutlet UISegmentedControl * intelligenceControl;

@property (nonatomic) NSArray * stories;
@property (nonatomic, readwrite) int feedPage;
@property (nonatomic, readwrite) BOOL pageFetching;
@property (nonatomic, readwrite) BOOL pageFinished;

- (void)resetFeedDetail;
- (void)fetchNextPage:(void(^)())callback;
- (void)fetchFeedDetail:(int)page withCallback:(void(^)())callback;
- (void)fetchRiverPage:(int)page withCallback:(void(^)())callback;
- (void)finishedLoadingFeed:(ASIHTTPRequest *)request;

- (void)renderStories:(NSArray *)newStories;
- (void)scrollViewDidScroll:(UIScrollView *)scroll;
- (IBAction)selectIntelligence;
- (void)changeIntelligence:(NSInteger)newLevel;
- (NSDictionary *)getStoryAtRow:(NSInteger)indexPathRow;
- (void)checkScroll;
- (void)setUserAvatarLayout:(UIInterfaceOrientation)orientation;

- (void)fadeSelectedCell;
- (IBAction)doOpenMarkReadActionSheet:(id)sender;
- (IBAction)doOpenSettingsActionSheet;
- (void)confirmDeleteSite;
- (void)deleteSite;
- (void)deleteFolder;
- (void)openMoveView;
- (void)showUserProfile;
- (void)changeActiveFeedDetailRow;
- (void)instafetchFeed;
- (void)changeActiveStoryTitleCellLayout;
- (void)loadFaviconsFromActiveFeed;
- (void)saveAndDrawFavicons:(ASIHTTPRequest *)request;
- (void)requestFailed:(ASIHTTPRequest *)request;
- (void)finishMarkAllAsRead:(ASIHTTPRequest *)request;
@end