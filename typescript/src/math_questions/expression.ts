import { Difficulty, GenerateChallenge, MathQuestionType } from '../models/math_question';
import { MathOperations } from './expression/models';

export const generateExpressionChallenge: GenerateChallenge = (difficulty: Difficulty, ops: MathOperations) => {
  return {
    difficulty,
    infix: '',
    latex: '',
    type: MathQuestionType.Expression,
  };
};
