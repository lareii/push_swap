<script setup>
import { getLog, toggleLog, clearLog } from '@/helpers/log.js';

const log = getLog();
</script>

<template>
  <div class="w-full h-full sticky top-0 p-10 pl-0 max-sm:hidden">
    <div class="text-sm mb-2">Log</div>
    <div class="overflow-y-auto p-5 h-96 bg-zinc-900">
      <code>
        <div v-for="(item, index) in log" :key="index">
          {{ item }}
        </div>
      </code>
    </div>
    <div class="flex gap-1 mt-1">
      <button @click="toggleLog" class="p-2 border">start/stop log</button>
      <button @click="clearLog" class="p-2 border">clear log</button>
    </div>
  </div>
</template>