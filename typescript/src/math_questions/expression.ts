import { Stack } from 'typescript-collections';
import { Difficulty, GenerateChallenge, MathQuestionType } from '../models/math_question';
import { getChallengeTokens } from './expression/generator';
import { ExprToken, MathOperations, Operator, TokenType } from './expression/models';

const getTemplateForOperator = (op: Operator, left: string, right: string): string => {
  switch (op) {
    case Operator.Addition: {
      return `(${left}+${right})`;
    }
    case Operator.Subtraction: {
      return `(${left}-${right})`;
    }
    case Operator.Mutliplication: {
      return `(${left}*${right})`;
    }
  }
  return '';
};
const expressionInfix = (tokens: ExprToken[]): string => {
  const exprStack: Stack<string> = new Stack();
  for (let i = tokens.length - 1; i >= 0; i--) {
    if (tokens[i].type === TokenType.Operator) {
      const currentOp = tokens[i].value as Operator;
      exprStack.push(getTemplateForOperator(currentOp, exprStack.pop()!, exprStack.pop()!));
    } else {
      exprStack.push(tokens[i].value.toString());
    }
  }
  return exprStack.pop()!;
};
export const generateExpressionChallenge: GenerateChallenge = (difficulty: Difficulty, ops: MathOperations) => {
  const tokens: ExprToken[] = getChallengeTokens(ops, difficulty);
  return {
    difficulty,
    infix: expressionInfix(tokens),
    latex: '',
    type: MathQuestionType.Expression,
  };
};
