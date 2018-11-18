import { Expr, ExprToken, TokenType, Operator } from './models';

export const getSubtractionExprTokens = (expr: Expr): ExprToken[] => {
  const tokens = [];
  tokens.push({
    type: TokenType.Operator,
    value: Operator.Mutliplication,
  });
  return tokens;
};
