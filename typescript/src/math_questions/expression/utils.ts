import { BoundedExpr, Expr, SubExprToken, TokenType } from './models';

export const isBounded = (expr: any): expr is BoundedExpr => {
  return 'bound' in expr;
};

export const getSubExprToken = (expr: Expr): SubExprToken => {
  return {
    bounded: false,
    type: TokenType.SubExpr,
    value: 0,
  };
};
