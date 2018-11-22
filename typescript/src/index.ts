import { getChallengeTokens } from './math_questions/expression/generator';
import { Operator } from './math_questions/expression/models';
import { generateFactorizationChallenge } from './math_questions/factorization';
import { Difficulty } from './models/math_question';

const basic = generateFactorizationChallenge(Difficulty.Basic, {});
const normal = generateFactorizationChallenge(Difficulty.Normal, {});
const advanced = generateFactorizationChallenge(Difficulty.Advanced, {});

console.log(basic);
console.log(normal);
console.log(advanced);

console.log(getChallengeTokens([Operator.Subtraction, Operator.Addition, Operator.Addition], Difficulty.Basic));
console.log(getChallengeTokens([Operator.Subtraction, Operator.Addition, Operator.Addition], Difficulty.Normal));
console.log(getChallengeTokens([Operator.Subtraction, Operator.Addition, Operator.Addition], Difficulty.Advanced));
