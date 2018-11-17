export enum MathQuestionType {
  Expression,
  Factorization,
  Binary,
  Hexadecimal,
}

export enum Difficulty {
  Basic,
  Normal,
  Advanced,
}

export interface ChallengeModel {
  type: MathQuestionType;
  difficulty: Difficulty;
  infix: string;
  latex: string;
}

export type GenerateChallenge = (difficulty: Difficulty) => ChallengeModel;
