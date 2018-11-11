export enum MathQuestionType {
  Expression,
  Factorization,
  Binary,
  Hexadecimal
}

export enum Difficulty {
  Basic,
  Normal,
  Advanced
}

export interface MathQuestionModel {
  type: MathQuestionType;
  difficulty: Difficulty;
}

export interface MathQuestionGenerator {
  generateQuestion: (difficulty: Difficulty) => MathQuestionModel,
  generateInfix: () => string,
  generateLatex: () => string,

}
