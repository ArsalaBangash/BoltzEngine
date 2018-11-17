export function random(min: number, max: number): number {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

export function positiveRandom(max: number): number {
  return random(1, max);
}
