export enum MathQuestionType {
  Expression,
  Factorization,
  Binary,
  Hexadecimal,
}

export enum Difficulty {
  Basic = 'basic',
  Normal = 'normal',
  Advanced = 'advanced',
}

export interface ChallengeModel {
  type: MathQuestionType;
  difficulty: Difficulty;
  infix: string;
  latex: string;
}

export type GenerateChallenge = (difficulty: Difficulty, params: any) => ChallengeModel;
