import { generateFactorizationChallenge } from './math_questions/factorization';
import { Difficulty } from './models/math_question';

const basic = generateFactorizationChallenge(Difficulty.Basic);
const normal = generateFactorizationChallenge(Difficulty.Normal);
const advanced = generateFactorizationChallenge(Difficulty.Advanced);

console.log(basic);
console.log(normal);
console.log(advanced);
