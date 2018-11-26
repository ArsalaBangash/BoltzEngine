import { generateExpressionChallenge } from './math_questions/expression';
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

console.log(getChallengeTokens([Operator.Subtraction, Operator.Mutliplication, Operator.Addition], Difficulty.Basic));
console.log(getChallengeTokens([Operator.Subtraction, Operator.Mutliplication, Operator.Addition], Difficulty.Normal));
console.log(
  getChallengeTokens([Operator.Subtraction, Operator.Mutliplication, Operator.Addition], Difficulty.Advanced)
);

let i = 0;
while (i < 10) {
  const b = generateExpressionChallenge(Difficulty.Basic, [
    Operator.Subtraction,
    Operator.Mutliplication,
    Operator.Addition,
  ]);
  const n = generateExpressionChallenge(Difficulty.Normal, [
    Operator.Subtraction,
    Operator.Mutliplication,
    Operator.Addition,
  ]);
  const a = generateExpressionChallenge(Difficulty.Advanced, [
    Operator.Subtraction,
    Operator.Mutliplication,
    Operator.Addition,
  ]);

  console.log(b);
  console.log(n);
  console.log(a);
  i++;
}
