
def test_remove_products_with_price_less():
    list_of_products = [{"name": "Butter", "price": 300, "quantity": 2}, {"name": "Milk", "price": 10, "quantity": 92}]
    remove_products_with_price_less_than_given_price(list_of_products,30)
    assert  list_of_products == [{"name": "Butter", "price": 300, "quantity": 2}]


def test_remove_products_with_price_bigger():
    list_of_products = [{"name": "Butter", "price": 10, "quantity": 2}, {"name": "Milk", "price": 500, "quantity": 92}]
    remove_products_with_price_bigger_than_given_price(list_of_products, 50)
    assert list_of_products == [{"name": "Butter", "price": 10, "quantity": 2}]


def create_product(list_of_products,product_name,product_price,product_quatity):
    return {"name":product_name,"price":product_price,"quantity":product_quatity}


def get_price(current_product):
    return current_product["price"]


def get_quantity(current_product):
    return current_product["quantity"]


def sort_list_by_price(list_of_products):
    list_of_products.sort(key=get_price)


def sort_list_by_quatity(list_of_products):
    list_of_products.sort(key=get_quantity)


def add_product_to_list(list_of_products,product_name,product_price,product_quatity):
    current_product=create_product(list_of_products,product_name,product_price,product_quatity)
    list_of_products.append(current_product)


def remove_products_with_price_less_than_given_price(list_of_products,product_price):
    length_of_list_of_product=len(list_of_products)
    for index in range(length_of_list_of_product):
        current_product=list_of_products[index]
        if current_product["price"] < product_price:
            list_of_products.pop(index)
            length_of_list_of_product-=1


def remove_products_with_price_bigger_than_given_price(list_of_products,product_price):
    length_of_list_of_product = len(list_of_products)
    for index in range(length_of_list_of_product):
        current_product=list_of_products[index]
        if current_product["price"] > product_price:
            list_of_products.pop(index)
            length_of_list_of_product-=1
