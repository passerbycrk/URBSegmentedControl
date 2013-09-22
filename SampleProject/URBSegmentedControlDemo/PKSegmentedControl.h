//
//  PKSegmentedControl.h
//  PKSegmentedControlDemo
//
//  Created by zhongsheng on 13-9-22.
//  Copyright (c) 2013年 PKan10 Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

enum {
	PKSegmentedControlOrientationHorizontal = 0,
	PKSegmentedControlOrientationVertical
};
typedef NSInteger PKSegmentedControlOrientation;

enum {
	PKSegmentViewLayoutDefault = 0,
	PKSegmentViewLayoutVertical
};
typedef NSInteger PKSegmentViewLayout;

@interface PKSegmentedControl : UISegmentedControl <UIAppearance>

typedef void (^PKSegmentedControlBlock)(NSInteger index, PKSegmentedControl *segmentedControl);

/**
 Layout behavior for the segments (row or columns).
 */
@property (nonatomic) PKSegmentedControlOrientation layoutOrientation;

/**
 Layout behavior of the segment contents.
 */
@property (nonatomic) PKSegmentViewLayout segmentViewLayout;

/**
 Block handle called when the selected segment has changed.
 */
@property (nonatomic, copy) PKSegmentedControlBlock controlEventBlock;

/**
 Background color for the base container view.
 */
@property (nonatomic, strong) UIColor *baseColor;

/**
 Stroke color used around the base container view.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 Stroke width for the base container view.
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 Corner radius for the base container view.
 */
@property (nonatomic) CGFloat cornerRadius;

/**
 Whether or not a gradient should be automatically applied to the base and segment backgrounds based on the defined base colors.
 */
@property (nonatomic, assign) BOOL showsGradient;

/**
 Padding between the segments and the base container view.
 */
@property (nonatomic, assign) UIEdgeInsets segmentEdgeInsets;

///----------------------------
/// @name Segment Customization
///----------------------------

@property (nonatomic, strong) UIColor *segmentBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *imageColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *selectedImageColor UI_APPEARANCE_SELECTOR;

@property (nonatomic, assign) UIEdgeInsets contentEdgeInsets;
@property (nonatomic, assign) UIEdgeInsets titleEdgeInsets;
@property (nonatomic, assign) UIEdgeInsets imageEdgeInsets;

- (id)initWithTitles:(NSArray *)titles;
- (id)initWithIcons:(NSArray *)icons;
- (id)initWithTitles:(NSArray *)titles icons:(NSArray *)icons;
- (void)insertSegmentWithTitle:(NSString *)title image:(UIImage *)image atIndex:(NSUInteger)segment animated:(BOOL)animated;
- (void)setSegmentBackgroundColor:(UIColor *)segmentBackgroundColor atIndex:(NSUInteger)segment;

- (void)setTextAttributes:(NSDictionary *)textAttributes forState:(UIControlState)state UI_APPEARANCE_SELECTOR;
- (void)setImageColor:(UIColor *)imageColor forState:(UIControlState)state UI_APPEARANCE_SELECTOR;
- (void)setSegmentBackgroundColor:(UIColor *)segmentBackgroundColor UI_APPEARANCE_SELECTOR;

- (void)setControlEventBlock:(PKSegmentedControlBlock)controlEventBlock;

@end

@interface UIImage (PKSegmentedControl)

- (UIImage *)imageTintedWithColor:(UIColor *)color;

@end