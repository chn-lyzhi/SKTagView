//
//  SKTagView.h
//
//  Created by Shaokang Zhao on 15/1/12.
//  Copyright (c) 2015 Shaokang Zhao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SKTag.h"

typedef enum : NSUInteger {
    SKTagViewSelectedNone,
    SKTagViewSelectedSingle,
    SKTagViewSelectedMultiple, //这里多选在 tagView 插入 Tag 的时候有 Bug。应该是插入没有更新 maxNumber
} SKTagViewSelected;

@interface SKTagView : UIView

@property (assign, nonatomic) UIEdgeInsets padding;
@property (assign, nonatomic) CGFloat lineSpacing;
@property (assign, nonatomic) CGFloat interitemSpacing;
@property (assign, nonatomic) CGFloat preferredMaxLayoutWidth;
@property (assign, nonatomic) BOOL singleLine;
@property (copy, nonatomic, nullable) void (^didTapTagAtIndex)(NSUInteger index);

@property (assign, nonatomic) SKTagViewSelected selectedType;

@property (assign, nonatomic) CGFloat maxSelectedNumber;  //当 type 为 SKTagViewSelectedMultiple 可用，可选最多数量

- (void)addTag: (nonnull SKTag *)tag;
- (void)insertTag: (nonnull SKTag *)tag atIndex:(NSUInteger)index;
- (void)removeTag: (nonnull SKTag *)tag;
- (void)removeTagAtIndex: (NSUInteger)index;
- (void)removeAllTags;

- ( NSArray * _Nullable )allSelectedTagsTitle;
- ( NSArray * _Nullable )allSelectedTags;

@end

