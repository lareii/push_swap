<script setup>
defineProps(['label', 'stack', 'stackCopy', 'controls']);

import { ref } from 'vue';
import { pushItem, copyStack } from '@/helpers/stack.js';

const inputValue = ref('');

function handleInput(event) {
  const value = event.target.value;
  inputValue.value = value.replace(/\D/g, '');
}

function clearInput() {
  inputValue.value = '';
}
</script>

<template>
  <div class="flex flex-col gap-2" :class="label === 'copy' && !stack.length && 'hidden'">
    <div class="text-sm whitespace-nowrap" :class="label === 'copy' && 'text-zinc-400'">
      {{ label !== 'copy' ? 'Stack ' + label : 'copy' }}
    </div>
    <div class="flex">
      <div v-if="controls" class="flex flex-col gap-1 mr-1">
        <button @click="pushItem(stack, inputValue) || clearInput()" class="w-10 h-10 border">➕</button>
        <button @click="stack.shift()" class="w-10 h-10 border">➖</button>
        <button @click="copyStack(stack, stackCopy)" class="w-10 h-10 border">📋</button>
      </div>
      <div class="h-fit text-lg"
        :class="(stack.length || controls) && (label === 'copy' ? 'border border-zinc-400' : 'border')">
        <div v-if="controls" class="flex items-center justify-center w-14 h-14">
          <input v-model="inputValue" @keyup.enter="pushItem(stack, inputValue) || clearInput()" @input="handleInput"
            type="text" placeholder="n" class="w-full h-full text-center bg-transparent outline-none" />
        </div>
        <div v-for="(item, index) in stack" :key="index" class="w-14 h-14">
          <div class="flex items-center justify-center h-full">
            {{ item }}
          </div>
        </div>
      </div>
    </div>
  </div>
</template>