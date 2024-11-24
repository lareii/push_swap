import { addLog } from "@/helpers/log.js";

export function push(stacks, label) {
  const transfer = (from, to, logLabel) => {
    if (from.length > 0) {
      to.unshift(from.shift());
      addLog(logLabel);
    }
  };

  if (label === 'a') transfer(stacks.stackB, stacks.stackA, 'pa');
  else if (label === 'b') transfer(stacks.stackA, stacks.stackB, 'pb');
}

export function swap(stacks, label) {
  const swapStack = (stack) => {
    if (stack.length >= 2) [stack[0], stack[1]] = [stack[1], stack[0]];
  };

  if (label === 'a') {
    swapStack(stacks.stackA);
    addLog('sa');
  } else if (label === 'b') {
    swapStack(stacks.stackB);
    addLog('sb');
  } else {
    swapStack(stacks.stackA);
    swapStack(stacks.stackB);
    addLog('ss');
  }
}

export function rotate(stacks, label) {
  const rotateStack = (stack) => {
    if (stack.length >= 2) stack.push(stack.shift());
  };

  if (label === 'a') {
    rotateStack(stacks.stackA);
    addLog('ra');
  } else if (label === 'b') {
    rotateStack(stacks.stackB);
    addLog('rb');
  } else {
    rotateStack(stacks.stackA);
    rotateStack(stacks.stackB);
    addLog('rr');
  }
}

export function reverseRotate(stacks, label) {
  const reverseRotateStack = (stack) => {
    if (stack.length >= 2) stack.unshift(stack.pop());
  };

  if (label === 'a') {
    reverseRotateStack(stacks.stackA);
    addLog('rra');
  } else if (label === 'b') {
    reverseRotateStack(stacks.stackB);
    addLog('rrb');
  } else {
    reverseRotateStack(stacks.stackA);
    reverseRotateStack(stacks.stackB);
    addLog('rrr');
  }
}
