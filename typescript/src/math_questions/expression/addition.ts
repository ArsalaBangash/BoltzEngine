import { randomNum } from '../../utils';
import {
  BoundedComplementTokens,
  BoundedExpr,
  DifficultyBounds,
  Expr,
  ExprToken,
  Operator,
  SubExprLocation,
  SubExprToken,
  TokenType,
} from './models';
import { getSubExprToken, isBounded } from './utils';

const difficultyBounds: DifficultyBounds = {
  basic: { min: 1, max: 10 },
  normal: { min: 5, max: 50 },
  // tslint:disable-next-line:object-literal-sort-keys
  advanced: { min: 20, max: 100 },
};

const _getZeroBoundTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  const zeroToken = { type: TokenType.Number, value: 0 };
  const zeroBoundedToken: SubExprToken = { type: TokenType.SubExpr, value: 0, bounded: true };
  switch (expr.subExprLocation) {
    case SubExprLocation.NEITHER: {
      return tokens.concat([zeroToken, zeroToken]);
    }
    case SubExprLocation.BOTH: {
      return tokens.concat([zeroBoundedToken, zeroBoundedToken]);
    }
    case SubExprLocation.LEFT: {
      return tokens.concat([zeroBoundedToken, zeroToken]);
    }
    case SubExprLocation.RIGHT: {
      return tokens.concat([zeroToken, zeroBoundedToken]);
    }
  }
};

const _getBoundedComplementTokens = (expr: Expr): BoundedComplementTokens => {
  const bound = (expr as BoundedExpr).bound;
  const boundedRandom = randomNum(difficultyBounds[expr.diff].min, bound);
  return {
    boundedToken: { type: TokenType.Number, value: boundedRandom },
    complementToken: { type: TokenType.Number, value: bound - boundedRandom },
  };
};

const _getRandomToken = (expr: Expr): ExprToken => {
  const randomValue = randomNum(difficultyBounds[expr.diff].min, difficultyBounds[expr.diff].max);
  return { type: TokenType.Number, value: randomValue };
};

const _getNoSubExprTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  if (expr.isBounded) {
    const bcTokens: BoundedComplementTokens = _getBoundedComplementTokens(expr);
    return tokens.concat([bcTokens.boundedToken, bcTokens.complementToken]);
  } else {
    const randomToken = _getRandomToken(expr);
    return tokens.concat([randomToken, randomToken]);
  }
};

const _getBothSubExprTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  if (expr.isBounded) {
    const bcTokens: BoundedComplementTokens = _getBoundedComplementTokens(expr);
    const boundedSubExprToken: SubExprToken = { type: TokenType.SubExpr, bounded: true, ...bcTokens.boundedToken };
    return tokens.concat([boundedSubExprToken, bcTokens.complementToken]);
  } else {
    const subExprToken: SubExprToken = getSubExprToken(expr);
    return tokens.concat([subExprToken, subExprToken]);
  }
};

const _getLeftSubExprTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  if (expr.isBounded) {
    const bcTokens: BoundedComplementTokens = _getBoundedComplementTokens(expr);
    const boundedSubExprToken: SubExprToken = { type: TokenType.SubExpr, bounded: true, ...bcTokens.boundedToken };
    return tokens.concat([boundedSubExprToken, bcTokens.complementToken]);
  } else {
    const subExprToken: SubExprToken = getSubExprToken(expr);
    const randomToken: ExprToken = _getRandomToken(expr);
    return tokens.concat([subExprToken, randomToken]);
  }
};

const _getRightSubExprTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  if (expr.isBounded) {
    const bcTokens: BoundedComplementTokens = _getBoundedComplementTokens(expr);
    const boundedSubExprToken: SubExprToken = { type: TokenType.SubExpr, bounded: true, ...bcTokens.boundedToken };
    return tokens.concat([boundedSubExprToken, bcTokens.complementToken]);
  } else {
    const subExprToken: SubExprToken = getSubExprToken(expr);
    const randomToken: ExprToken = _getRandomToken(expr);
    return tokens.concat([randomToken, subExprToken]);
  }
};

export const getAdditionExprTokens = (expr: Expr): ExprToken[] => {
  const tokens: ExprToken[] = [];
  tokens.push({
    type: TokenType.Operator,
    value: Operator.Addition,
  });
  if (isBounded(expr) && expr.bound === 0) {
    return tokens.concat(_getZeroBoundTokens(expr));
  }
  switch (expr.subExprLocation) {
    case SubExprLocation.NEITHER: {
      return tokens.concat(_getNoSubExprTokens(expr));
    }
    case SubExprLocation.BOTH: {
      return tokens.concat(_getBothSubExprTokens(expr));
    }
    case SubExprLocation.LEFT: {
      return tokens.concat(_getLeftSubExprTokens(expr));
    }
    case SubExprLocation.RIGHT: {
      return tokens.concat(_getRightSubExprTokens(expr));
    }
  }
};
