import {
  Difficulty,
  MathQuestionGenerator,
  MathQuestionModel,
  MathQuestionType
} from "../models/math_question";
import { positiveRandom } from "../utils";

interface FactorizationModel extends MathQuestionModel {
  xCoeff1: number;
  xCoeff2: number;
  const1: number;
  const2: number;
}

interface FactorizationRandomBounds {
  xCoeffMax: number;
  constMax: number;
}

class FactorizationGenerator implements MathQuestionGenerator {
  public generateQuestion(difficulty: Difficulty): FactorizationModel {
    return this._factorizationQuestion(difficulty);
  }

  public generateInfix(): string {
    return "";
  }

  public generateLatex(): string {
    return "";
  }

  private _factorizationQuestion(difficulty: Difficulty): FactorizationModel {
    const randomBounds = this._getRandomBounds(difficulty);
    return {
      const1: positiveRandom(randomBounds.xCoeffMax),
      const2: positiveRandom(randomBounds.xCoeffMax),
      difficulty,
      type: MathQuestionType.Factorization,
      xCoeff1: positiveRandom(randomBounds.xCoeffMax),
      xCoeff2: positiveRandom(randomBounds.xCoeffMax)
    };
  }

  private _getRandomBounds(difficulty: Difficulty): FactorizationRandomBounds {
    switch (difficulty) {
      case Difficulty.Basic: {
        return { xCoeffMax: 1, constMax: 5 };
      }
      case Difficulty.Normal: {
        return { xCoeffMax: 2, constMax: 10 };
      }
      case Difficulty.Advanced: {
        return { xCoeffMax: 3, constMax: 10 };
      }
    }
  }
}
