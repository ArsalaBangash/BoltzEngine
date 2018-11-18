import { TokenType, Expr, ExprToken, Operator } from './models';

export const getMultiplicationExprTokens = (expr: Expr): ExprToken[] => {
  const tokens = [];
  tokens.push({
    type: TokenType.Operator,
    value: Operator.Mutliplication,
  });
  return tokens;
};
