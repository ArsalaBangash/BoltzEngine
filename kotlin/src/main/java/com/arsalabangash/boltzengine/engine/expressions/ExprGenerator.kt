package com.arsalabangash.boltzengine.engine.expressions

import com.arsalabangash.boltzengine.engine.enums.Level
import com.arsalabangash.boltzengine.engine.enums.MathOperation
import com.arsalabangash.boltzengine.engine.enums.SubExprLocation
import java.util.*

class ExprGenerator {

    val randomGenerator = Random()

    /**
     * This class is generated when an [ExprToken] with a sub-expression with it's respective [bound]
     * is found, with the original expression being split to the left and right of the
     * [ExprToken] with the sub-expression
     */
    data class ExprWithSub(val bound: Int?,
                           val leftSide: ArrayList<ExprToken>,
                           val rightSide: ArrayList<ExprToken>)

    /**
     * Reduces the question of operations left in the current expression based on the location of the
     * empty tokens processed.
     */
    fun reduceOperationsBy(subExprLocation: SubExprLocation): Int {
        when (subExprLocation) {
            SubExprLocation.LEFT, SubExprLocation.RIGHT -> return 1
            SubExprLocation.BOTH -> return 2
            else -> return 0
        }
    }

    /**
     * Based on the [operationsLeft] for a particular expression, this function will return
     * the locations for the empty tokens.
     */
    fun getEmptyTokenLocations(operationsLeft: Int): SubExprLocation {
        when (operationsLeft) {
            0, 1 ->
                return SubExprLocation.NEITHER

            2 ->
                if (randomGenerator.nextDouble() > 0.50) return SubExprLocation.LEFT
                else return SubExprLocation.RIGHT

        //An equal 1/3 chance for all EmptyTokenLocations when there are more than 2 ops left
            else -> {
                val chooseNumEmpty = randomGenerator.nextDouble()
                if (chooseNumEmpty < 0.33) return SubExprLocation.BOTH
                else if (chooseNumEmpty > 0.66) return SubExprLocation.LEFT
                else return SubExprLocation.RIGHT
            }
        }
    }

    /**
     * Given ar ArrayList of MathOperations and a Level paramater indicating the difficulty, return an 
     * expression in the form of an ArrayList of ExprTokens
     *
     * The expression returned will be in reverse polish notation
     * e.g The expression (3 + (1-2)) will be [+, 3, -, 1, 2]
     */
    fun generateExpression(operations: ArrayList<MathOperation>, level: Level): ArrayList<ExprToken> {
        var operationsLeft = operations.size
        var expression = ArrayList<ExprToken>()
        var currentOp: MathOperation = operations[randomGenerator.nextInt(operations.size)]

        //Determines whether the current operation will have numbers or sub-expressions on either side
        var subExprLocation: SubExprLocation = getEmptyTokenLocations(operationsLeft)

        operationsLeft -= reduceOperationsBy(subExprLocation)
        operations.remove(currentOp)
        expression.addAll(MathExpr.createExpression(currentOp, null, level)!!
                .produceExpression(subExprLocation))
        var exprWithSub = checkSubExprTokens(expression)
        
        //While sub-expressions still exist, we'll continue to add to the expression
        while (exprWithSub != null) {
            currentOp = operations[randomGenerator.nextInt(operations.size)]
            subExprLocation = getEmptyTokenLocations(operationsLeft)
            expression = exprWithSub.leftSide

            //Add the newly generated sub-expression to the global expression
            if (exprWithSub.bound != null) {
                expression.addAll((MathExpr.createExpression(currentOp, exprWithSub.bound, level) as MathExpr)
                        .produceExpression(subExprLocation))
            } else {
                expression.addAll(MathExpr.createExpression(currentOp, null, level)!!
                        .produceExpression(subExprLocation))
            }

            //Add the right side of the previously global expression and check again for any Sub-Expression Tokens
            expression.addAll(exprWithSub.rightSide)
            operations.remove(currentOp)
            operationsLeft -= reduceOperationsBy(subExprLocation)
            exprWithSub = checkSubExprTokens(expression)
        }

        return expression
    }

    /**
     * Scans the [expressionList] for any sub-expression tokens. When one is found, the original
     * expression is converted to a [ExprWithSub]
     */
    fun checkSubExprTokens(expressionList: ArrayList<ExprToken>): ExprWithSub? {
        for (i in expressionList.indices) {
            if (expressionList[i].hasSubExpr) {
                val bound = expressionList[i].intVal
                expressionList.removeAt(i)
                val preEmptyTokens = ArrayList(expressionList.subList(0, i))
                val postEmptyTokens = ArrayList(expressionList.subList(i, expressionList.size))
                return ExprWithSub(bound, preEmptyTokens, postEmptyTokens)
            }
        }
        return null
    }
}