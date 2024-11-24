import { useStorage } from '@vueuse/core';

const log = useStorage('log', []);
const logFlag = useStorage('logFlag', false);

export function getLog() {
  return log.value;
}

export function toggleLog() {
  logFlag.value = !logFlag.value;
}

export function addLog(item) {
  if (logFlag.value) log.value.push(`${log.value.length}: ${item}`);
}

export function clearLog() {
  log.value.length = 0;
}