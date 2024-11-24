<script setup>
defineProps(['stacks']);

import { clearStacks } from '@/helpers/stack.js';
import { push, swap, rotate, reverseRotate } from '@/helpers/operations.js';
</script>

<template>
  <div class="h-screen p-10 pr-0 flex flex-col justify-between sticky top-0">
    <div class="flex flex-col gap-1">
      <button @click="push(stacks, 'a')" class="w-10 h-10 border">pa</button>
      <button @click="push(stacks, 'b')" class="w-10 h-10 border">pb</button>
      <button @click="swap(stacks, 'a')" class="w-10 h-10 border">sa</button>
      <button @click="swap(stacks, 'b')" class="w-10 h-10 border">sb</button>
      <button @click="swap(stacks, 'ab')" class="w-10 h-10 border">ss</button>
      <button @click="rotate(stacks, 'a')" class="w-10 h-10 border">ra</button>
      <button @click="rotate(stacks, 'b')" class="w-10 h-10 border">rb</button>
      <button @click="rotate(stacks, 'ab')" class="w-10 h-10 border">rr</button>
      <button @click="reverseRotate(stacks, 'a')" class="w-10 h-10 border">rra</button>
      <button @click="reverseRotate(stacks, 'b')" class="w-10 h-10 border">rrb</button>
      <button @click="reverseRotate(stacks, 'ab')"
        class="w-10 h-10 border">rrr</button>
    </div>
    <div class="flex flex-col gap-1">
      <button @click="clearStacks(stacks)" class="w-10 h-10 border">clr</button>
      <a href="https://github.com/lareii/push_swap" target="_blank" class="w-10 h-10 border flex items-center justify-center">⭐</a>
    </div>
  </div>
</template>