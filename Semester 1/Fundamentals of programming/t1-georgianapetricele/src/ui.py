import functions


def print_menu():
    print("1. add <product_name> <quantity> <item_price>")
    print("2. remove <less/greater> <price>")
    print("3. list <price>")
    print("4. list <quantity>")


def ui_print_products_by_price(list_of_products):
    functions.sort_list_by_price(list_of_products)
    print(list_of_products)


def ui_print_products_by_quantity(list_of_products):
    functions.sort_list_by_quatity(list_of_products)
    print(list_of_products)


def ui_add_product_to_list(list_of_products,product_name,product_price,product_quatity):
    try:
        if product_name == "" or product_quatity=="" or  product_price<0 or product_quatity<0:
            raise ValueError("Product can't be added")
        else:
            functions.add_product_to_list(list_of_products, product_name, product_price, product_quatity)
    except ValueError as err:
        print(err)


def start():
    list_of_products=[{"name":"Butter","price":30,"quantity":2},{"name":"Milk","price":10,"quantity":92},
                      {"name":"Bread","price":8,"quantity":300},{"name":"Soda","price":20,"quantity":200}]
    while True:
        command=input("Enter your command: ")
        if command=="add":
             product_name=""
             product_quantity=-100
             product_price=-100
             product_name=input("Enter the name of current product: ")
             if product_name == "":
                 print("Product can't be added")
                 break
             try:
                 product_quantity=int(input("Enter the product quantity: "))
             except ValueError:
                 print("Product can't be added")
             try:
                 product_price=int(input("Enter the product price: "))
             except ValueError:
                 print("Product can't be added")
             ui_add_product_to_list(list_of_products,product_name,product_price,product_quantity)
        elif command == "remove":
            comparator=input("Enter the comparator > or  < : ")
            price=int(input("Enter the product price: "))
            if comparator == "<":
                functions.remove_products_with_price_less_than_given_price(list_of_products,price)
            elif comparator == ">":
                functions.remove_products_with_price_bigger_than_given_price(list_of_products,price)
        elif command == "list":
            sorting_criteria=input("Enter the sorting criteria: ")
            if sorting_criteria == "price":
                ui_print_products_by_price(list_of_products)
            elif sorting_criteria == "quantity":
                ui_print_products_by_quantity(list_of_products)
        elif command == "exit":
            break



start()














