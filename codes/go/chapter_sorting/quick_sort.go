// File: quick_sort.go
// Created Time: 2022-12-12
// Author: msk397 (machangxinq@gmail.com)

package chapter_sorting

// 快速排序
type QuickSort struct{}

// 快速排序（中位基准数优化）
type QuickSortMedian struct{}

// 快速排序（尾递归优化）
type QuickSortTailCall struct{}

/* 哨兵划分 */
func (q *QuickSort) partition(nums []int, left, right int) int {
	// 以 nums[left] 作为基准数
	i, j := left, right
	for i < j {
		for i < j && nums[j] >= nums[left] {
			j-- // 从右向左找首个小于基准数的元素
		}
		for i < j && nums[i] <= nums[left] {
			i++ // 从左向右找首个大于基准数的元素
		}
		// 元素交换
		nums[i], nums[j] = nums[j], nums[i]
	}
	// 将基准数交换至两子数组的分界线
	nums[i], nums[left] = nums[left], nums[i]
	return i // 返回基准数的索引
}

/* 快速排序 */
func (q *QuickSort) quickSort(nums []int, left, right int) {
	// 子数组长度为 1 时终止递归
	if left >= right {
		return
	}
	// 哨兵划分
	pivot := q.partition(nums, left, right)
	// 递归左子数组、右子数组
	q.quickSort(nums, left, pivot-1)
	q.quickSort(nums, pivot+1, right)
}

/* 选取三个元素的中位数 */
func (q *QuickSortMedian) medianThree(nums []int, left, mid, right int) int {
	if (nums[left] > nums[mid]) != (nums[left] > nums[right]) {
		return left
	} else if (nums[mid] < nums[left]) != (nums[mid] > nums[right]) {
		return mid
	}
	return right
}

/* 哨兵划分（三数取中值）*/
func (q *QuickSortMedian) partition(nums []int, left, right int) int {
	// 以 nums[left] 作为基准数
	med := q.medianThree(nums, left, (left+right)/2, right)
	// 将中位数交换至数组最左端
	nums[left], nums[med] = nums[med], nums[left]
	// 以 nums[left] 作为基准数
	i, j := left, right
	for i < j {
		for i < j && nums[j] >= nums[left] {
			j-- //从右向左找首个小于基准数的元素
		}
		for i < j && nums[i] <= nums[left] {
			i++ //从左向右找首个大于基准数的元素
		}
		//元素交换
		nums[i], nums[j] = nums[j], nums[i]
	}
	//将基准数交换至两子数组的分界线
	nums[i], nums[left] = nums[left], nums[i]
	return i //返回基准数的索引
}

/* 快速排序 */
func (q *QuickSortMedian) quickSort(nums []int, left, right int) {
	// 子数组长度为 1 时终止递归
	if left >= right {
		return
	}
	// 哨兵划分
	pivot := q.partition(nums, left, right)
	// 递归左子数组、右子数组
	q.quickSort(nums, left, pivot-1)
	q.quickSort(nums, pivot+1, right)
}

/* 哨兵划分 */
func (q *QuickSortTailCall) partition(nums []int, left, right int) int {
	// 以 nums[left] 作为基准数
	i, j := left, right
	for i < j {
		for i < j && nums[j] >= nums[left] {
			j-- // 从右向左找首个小于基准数的元素
		}
		for i < j && nums[i] <= nums[left] {
			i++ // 从左向右找首个大于基准数的元素
		}
		// 元素交换
		nums[i], nums[j] = nums[j], nums[i]
	}
	// 将基准数交换至两子数组的分界线
	nums[i], nums[left] = nums[left], nums[i]
	return i // 返回基准数的索引
}

/* 快速排序（尾递归优化）*/
func (q *QuickSortTailCall) quickSort(nums []int, left, right int) {
	// 子数组长度为 1 时终止
	for left < right {
		// 哨兵划分操作
		pivot := q.partition(nums, left, right)
		// 对两个子数组中较短的那个执行快排
		if pivot-left < right-pivot {
			q.quickSort(nums, left, pivot-1) // 递归排序左子数组
			left = pivot + 1                 // 剩余待排序区间为 [pivot + 1, right]
		} else {
			q.quickSort(nums, pivot+1, right) // 递归排序右子数组
			right = pivot - 1                 // 剩余待排序区间为 [left, pivot - 1]
		}
	}
}
