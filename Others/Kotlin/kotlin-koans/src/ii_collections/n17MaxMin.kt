package ii_collections

fun example4() {
    val max = listOf(1, 42, 4).max()
    val longestString = listOf("a", "b").maxBy { it.length }
}

fun Shop.getCustomerWithMaximumNumberOfOrders(): Customer? {
    return this.customers.maxBy { it.orders.size }
}

fun Customer.getMostExpensiveOrderedProduct(): Product? {
    return this.orderedProducts.maxBy { it.price }
}
