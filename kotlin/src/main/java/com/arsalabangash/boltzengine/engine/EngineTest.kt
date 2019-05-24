package com.arsalabangash.boltzengine.engine

import com.arsalabangash.boltzengine.engine.enums.Level
import com.arsalabangash.boltzengine.engine.enums.MathOperation
import com.arsalabangash.boltzengine.engine.expressions.ExprGenerator
import com.arsalabangash.boltzengine.engine.expressions.ExprToken
import java.util.*

val gen = ExprGenerator()
val infix = InfixConverter()

fun main(args: Array<String>) {
//    val mathOps = arrayListOf<MathOperation>(MathOperation.Modulus)
//    val startTime = System.currentTimeMillis()
//    val numExpressions = 100000
//    for (i in 1..numExpressions) {
//        val ops = arrayListOf<MathOperation>(MathOperation.Addition, MathOperation.Subtraction,
//                MathOperation.Division, MathOperation.Multiplication)
////        printExpr(gen.generateExpression(ops, Level.Advanced))
//        gen.generateExpression(ops, Level.Advanced)
//    }
//    val endTime = System.currentTimeMillis()
//    println("Generated $numExpressions expressions in " + (endTime - startTime) + " milliseconds")

    val numExpressions = 100000L
    var acc = 0L
    (1..20).forEach {
        acc += testTime(numExpressions)
    }
    val a = 1000
    println("Generated $numExpressions expressions in " + (acc / 20) + " milliseconds")
    val b = 3

}

fun testTime(numExpressions: Long): Long {
    val startTime = System.currentTimeMillis()
    for (i in 1..numExpressions) {
        val ops = arrayListOf<MathOperation>(MathOperation.Addition, MathOperation.Subtraction,
                MathOperation.Division, MathOperation.Multiplication)
//        printExpr(gen.generateExpression(ops, Level.Advanced))
        gen.generateExpression(ops, Level.Advanced)
    }
    val endTime = System.currentTimeMillis()
    return endTime - startTime
}

fun printExpr(expr: ArrayList<ExprToken>) {
    println(infix.exprToInfix(expr))
}

fun getOps(mathOps: ArrayList<MathOperation>): ArrayList<MathOperation> {
    var numberOps = Random().nextInt(2) + 1
    val ops = arrayListOf<MathOperation>()
    while (numberOps > 0) {
        ops.add(mathOps[Random().nextInt(mathOps.size)])
        numberOps--
    }
    return ops
}