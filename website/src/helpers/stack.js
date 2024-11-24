import { clearLog } from "@/helpers/log.js";

export function pushItem(stack, item) {
  stack.unshift(item ? Number(item) : 0);
}

export function copyStack(stack, stackCopy) {
  stackCopy.length = 0;
  stack.forEach((item) => stackCopy.push(item));
}

export function clearStacks(stacks) {
  stacks.stackA.length = 0;
  stacks.stackB.length = 0;
  stacks.stackACopy.length = 0;
  clearLog();
}