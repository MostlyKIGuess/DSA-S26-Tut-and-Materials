use std::collections::{BinaryHeap, HashMap};
use std::cmp::Reverse;

struct DoubleHeap{
    lo: BinaryHeap<i64>, // lower elements, max heap
    hi: BinaryHeap<Reverse<i64>>, // higher elements, min heap
    lazy: HashMap<i64,usize>, // what to delete
    lo_size: i64,
    hi_size: i64,
}

impl DoubleHeap {
    fn new() -> Self {
        DoubleHeap {
            lo: BinaryHeap::new(),
            hi: BinaryHeap::new(),
            lazy: HashMap::new(),
            lo_size: 0,
            hi_size: 0,
        }
    }

    fn remove_lo(&mut self) {
        while let Some(&top) = self.lo.peek() {
            if let Some(&count) = self.lazy.get(&top) {
                if count > 0 {
                    self.lazy.insert(top, count - 1);
                    self.lo.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    fn remove_hi(&mut self) {
        while let Some(&Reverse(top)) = self.hi.peek() {
            if let Some(&count) = self.lazy.get(&top) {
                if count > 0 {
                    self.lazy.insert(top, count - 1);
                    self.hi.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    fn push(&mut self, num: i64) {
        if self.lo.is_empty() || num <= *self.lo.peek().unwrap() {
            self.lo.push(num);
            self.lo_size += 1;
        } else {
            self.hi.push(Reverse(num));
            self.hi_size += 1;
        }
        self.balance();
    }

    fn remove(&mut self, num: i64){
        *self.lazy.entry(num).or_insert(0) += 1;
        if num <= *self.lo.peek().unwrap() {
            self.lo_size -= 1;
        } else {
            self.hi_size -= 1;
        }
        self.balance();
    }

    fn balance(&mut self) {
        if self.lo_size > self.hi_size + 1 {
            let top = self.lo.pop().unwrap();
            self.hi.push(Reverse(top));
            self.lo_size -= 1;
            self.hi_size += 1;
        } else if self.lo_size < self.hi_size {
            let Reverse(top) = self.hi.pop().unwrap();
            self.lo.push(top);
            self.lo_size += 1;
            self.hi_size -= 1;
        }
    }


    fn median(&mut self, k: usize) -> f64 {
        self.remove_lo();
        self.remove_hi();
        if k % 2 == 1 {
            *self.lo.peek().unwrap() as f64
        } else {
            (*self.lo.peek().unwrap() as f64 + self.hi.peek().unwrap().0 as f64) / 2.0
        }
    }
}

struct Solution;

impl Solution {
    pub fn median_sliding_window(nums: Vec<i32>, k: i32) -> Vec<f64> {
        let mut heap = DoubleHeap::new();
        let mut result = Vec::new();
        let k = k as usize;
        for (i, &num) in nums.iter().enumerate() {
            heap.push(num as i64);
            if i >= k {
                heap.remove(nums[i - k] as i64);
            }
            if i >= k - 1 {
                result.push(heap.median(k));
            }
        }
        result
    }
}

fn main() {
    let nums = vec![1, 3, -1, -3, 5, 3, 6, 7];
    let k = 3;
    println!("{:?}", Solution::median_sliding_window(nums, k));
    // [1.0, -1.0, -1.0, 3.0, 5.0, 6.0]

    let nums2 = vec![1, 2, 3, 4, 2, 3, 1, 4, 2];
    let k2 = 3;
    println!("{:?}", Solution::median_sliding_window(nums2, k2));
    // [2.0, 3.0, 3.0, 3.0, 2.0, 3.0, 2.0]
}
