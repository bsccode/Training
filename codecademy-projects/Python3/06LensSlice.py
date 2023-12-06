
#You work at Len’s Slice, a new pizza joint in the neighborhood. You are going to use your knowledge of Python lists to organize some of your sales data.

# Your code below:
toppings = ["pepperoni","pineapple","cheese","sausage","olives","anchovies","mushrooms"]

prices = [2,6,1,3,2,7,2]

num_two_dollar_slices = prices.count(2)

print(num_two_dollar_slices)

num_pizzas = len(toppings)

print("We sell " + str(num_pizzas)  + " different kinds of pizza!")

zipprices = zip(prices,toppings)

pizza_and_prices = list(zipprices)

print(pizza_and_prices)
pizza_and_prices.sort()
print(pizza_and_prices)

cheapest_pizza = pizza_and_prices[0][1]

priciest_pizza = pizza_and_prices[-1][1]

pizza_and_prices.pop()

three_cheapest = pizza_and_prices[:3]

print(three_cheapest)

peppers = [2.5,"peppers"]

pizza_and_prices.insert[4 , peppers]

print(pizza_and_prices)
