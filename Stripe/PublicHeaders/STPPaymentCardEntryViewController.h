//
//  STPPaymentCardEntryViewController.h
//  Stripe
//
//  Created by Jack Flintermann on 3/23/16.
//  Copyright © 2016 Stripe, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "STPBlocks.h"
#import "STPCardParams.h"
#import "STPAPIClient.h"
#import "STPAddress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  This callback will be yielded with two arguments: a Stripe token (may be nil, if the user cancels the form) and another callback. If the token is present, you can submit it to your backend API to either create a charge or attach it to a customer. When that is done, call tokenCompletion with any error that occurred (it'll be shown to the user and they'll be able to resubmit the form). If your backend API call succeeds, you should dismiss the view controller and move the user to the next step of your UI.
 *
 *  @param token           A valid Stripe token, or nil if the user presses the "cancel" button.
 *  @param tokenCompletion A callback to call once you're done passing the token to your server.
 */
typedef void (^STPPaymentCardEntryBlock)(STPToken * __nullable token, STPErrorBlock tokenCompletion);

/** This view controller contains a credit card entry form that the user can fill out. On submission, it will use the Stripe API to convert the user's card details to a Stripe token. It renders a right bar button item that submits the form, so it must be shown inside a UINavigationController.
 */
@interface STPPaymentCardEntryViewController : UIViewController

/**
 *  Returns a new view controller with a credit card form.
 *
 *  @param apiClient                    An API client to communicate with Stripe. You can pass [STPAPIClient sharedClient] here.
 *  @param requiredBillingAddressFields The billing address fields the user must fill out in order for the form to validate. These fields will all be present on the returned token from Stripe. See https://stripe.com/docs/api#create_card_token for more information.
 *  @param completion                   A block that will be called when the user has successfully submitted their information, or pressed cancel. If they submit their information, the token parameter will be a valid STPToken object. If they cancel, it will be nil. When this is called, the user will see a spinner on the form. This gives your application time to send the token to your backend and add it to a customer or complete a charge. When you're done, call the `tokenCompletion` parameter with whether or not your call succeeded.
 *
 *  @return a view controller that you can either embed in a UINavigationController and present modally, or push onto an existing UINavigationController stack.
 */
- (instancetype)initWithAPIClient:(STPAPIClient *)apiClient
     requiredBillingAddressFields:(STPBillingAddressFields)requiredBillingAddressFields
                       completion:(STPPaymentCardEntryBlock)completion;

@end

NS_ASSUME_NONNULL_END
