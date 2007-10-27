#if !defined(_VnseaApp_h_)
#define _VnseaApp_h_

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/CDStructures.h>
#import <UIKit/UIWindow.h>
#import <UIKit/UIView-Hierarchy.h>
#import <UIKit/UIHardware.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIScroller.h>
#import <UIKit/UITransitionView.h>
#import "VNCView.h"
#import "VNCServerInfoView.h"
#import "VNCServerListView.h"

@class Profile;

//! @brief Device orientation constants.
enum _device_orient
{
	kUIDeviceOrientationNormal = 1,
	kUIDeviceOrientationUpsideDown = 2,
	kUIDeviceOrientationTurnedLeft = 3,
	kUIDeviceOrientationTurnedRight = 4
};

/*!
 * @brief Main application class for the VNC viewer program.
 *
 * This class manages the high level interaction with the user. It
 * switches between the server list, server editor, and connection views
 * as necessary. It also handles reading and writing the saved list
 * of servers to and from media.
 */
@interface VnseaApp : UIApplication
{
	UIWindow * _window;
	UIView * _mainView;
	UITransitionView * _transView;
	UIScroller * _vncScroller;
	VNCView * _vncView;
	Profile * _defaultProfile;
	VNCServerListView * _serversView;
	VNCServerInfoView * _serverEditorView;
	int _editingIndex;	//!< Index of the server currently being edited.
}

//! \name Server list I/O
//@{
- (NSArray *)loadServers;
- (void)saveServers:(NSArray *)theServers;
//@}

//! \name List and editor delegate messages
//@{
- (void)serverSelected:(int)serverIndex;
- (void)editServer:(int)serverIndex;
- (void)addNewServer;
- (void)finishedEditingServer:(NSDictionary *)serverInfo;
- (void)deleteServer;
//@}

//! @brief Creates a dictionary populated with default server values.
- (NSDictionary *)defaultServerInfo;

//! \name Auto-update support
//@{
- (void)checkForUpdate;
//@}

//! @brief Show the abourt alert.
- (void)displayAbout;

@end

#endif // _VnseaApp_h_