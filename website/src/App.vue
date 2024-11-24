<script setup>
import { useStorage } from '@vueuse/core';
import Sidebar from '@/components/Sidebar.vue';
import Stack from '@/components/Stack.vue';
import Log from '@/components/Log.vue';

const stackA = useStorage('stack_a', [1, 3, 3, 7, 4, 2]);
const stackB = useStorage('stack_b', []);
const stackACopy = useStorage('stack_a_copy', []);
</script>

<template>
  <div class="flex h-full">
    <Sidebar :stacks="{ stackA, stackB, stackACopy }" />
    <div class="flex w-full h-full">
      <div class="p-10 flex gap-5 h-full">
        <Stack label="copy" :stack="stackACopy" :controls="false" />
        <Stack label="A" :stack="stackA" :stackCopy="stackACopy" :controls="true" />
        <Stack label="B" :stack="stackB" :controls="false" />
      </div>
      <Log />
    </div>
  </div>
</template>