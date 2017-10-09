//
//  VSAlertController.h
//  VSAlertController
//
//  Created by Varun Santhanam on 10/8/17.
//

@import UIKit;

#import "VSAlertAction.h"

extern NSString * _Nonnull const VSAlertActionNotImplementedException;

/**
 An enuration for the various ui styles of VSAlertController

 - VSAlertControllerStyleAlert: A pop up alert that displays at 270px wide (like Apple's UIAlertController)
 - VSAlertControllerStyleWalkthroughAlert: A wider popup that stretches it's to fit the width of the device (minus some padding_
 - VSAlertControllerStyleActionSheet: A bottom of the screen alert (NOT IMPLEMENTED)
 */
typedef NS_ENUM(NSInteger, VSAlertControllerStyle) {
  
    VSAlertControllerStyleAlert,
    VSAlertControllerStyleWalkthroughAlert,
    VSAlertControllerStyleActionSheet
    
};

/**
 VSAlertController is a drop-in replacement for UIAlertController with a bit more customization and better looks. It's largely based on Codeido's PMAlertController, but has been re-written in Objective-C rather than Swift, and supports a few more features like dynamically sorted alert actions and a "destructive" action style that was missing in PMAlertController. It doesn't requrie a separate XIB file for better potability, and uses the system font by default for a more vanilla look. VSAlertController can can be customized at the class level, so you can make any/all UI changes once.
 */
@interface VSAlertController : UIViewController

/**
 @name Class Properties
 */

/**
 The color of the text used by alert controllers. The default value is the system font at size 15. (Class property, applies to all instances created after change)
 */
@property (NS_NONATOMIC_IOSONLY, class, nonnull) UIColor *textColor;

/**
 The color of the title text used by alert controllers. The default value is nil. If nil is specified when an alert controller is displayed, VSAlertController.textColor's value is used instead. (Class property, applies to all instances created after change)
 */
@property (NS_NONATOMIC_IOSONLY, class, nullable) UIColor *titleTextColor;

/**
 @name Instance Properties
 */

/**
 An array of UITextFields visible on the alert
 */
@property (NS_NONATOMIC_IOSONLY, strong, readonly, nonnull) NSArray<UITextField *> *textFields;

/**
 @name Class Methods
 */

/**
 A factory method to create a new alert. The alert is dynamically sized based on your initialization paramaters

 @param title The title of the alert.
 @param description The message or body of the alert.
 @param image The image to show on the alert, if any. See the provided image template for details.
 @param style The UI style of the alert
 @return The initialized alert controller.
 */
+ (nullable instancetype)alertControllerWithTitle:(nullable NSString *)title description:(nullable NSString *)description image:(nullable UIImage *)image style:(VSAlertControllerStyle)style;

/**
 @name Instance Methods
 */

/**
 Create a new alert controller

 @param title The title of the alert.
 @param description The message or body of the alert.
 @param image The image to show on the alert, if any. See the provided image template for details.
 @param style The UI style of the alert
 @return The initialized alert controller.
 */
- (nullable instancetype)initWithTitle:(nullable NSString *)title description:(nullable NSString *)description image:(nullable UIImage *)image style:(VSAlertControllerStyle)style;

/**
 Add an action to the alert controller. See VSAlertAction's documentation for more information

 @param alertAction The action to add to the controller
 */
- (void)addAction:(nonnull VSAlertAction *)alertAction;

/**
 Add a text field to the alert controller. Rather than instantiating the UITextField yourself, use the configuration block (which provides you an already initialized UITextField, and make your customizations there. Unlike in PMAlertController, you can re-assign the the UITextField's delegate property -- VSAlertController does not make use of UITextField to infer when to dismiss and show the keyboard.

 @param configuration the block used to configure or style the textfield
 */
- (void)addTextField:(void (^_Nullable)(UITextField * _Nonnull textField))configuration;

@end