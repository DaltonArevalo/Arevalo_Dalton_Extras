#include "persons_controller.h"
#include "person_builder.h"
#include "utils.h"
#include "person.h"
#include <iostream>
#include <regex>
#include <vector>
#include <sstream>
#include <fstream>

PersonsController::PersonsController(Application *app) : Controller(app), menu_(Menu("Amortizacion / personas")) {}

void PersonsController::init() {
    PersonQuery query{make_storage_query()};
    auto rows = query.storage.get_all<PersonPojo>();
    int index = 0;

    for (auto row : rows) {
        Person person(row.id, row.firstname, row.lastname, row.address, row.phone, row.email);
        persons_.push_front(person);
        persons_.push_back(person);
        persons_.remove_at(index);
        persons_.size();
    }

    // registar opcion del menu para registrar nuevas personas
    menu_.add_option(MenuOption("Registrar nueva persona por la cabeza", [&] (MenuOptionArguments args) {
        register_person_front();
    }));

    menu_.add_option(MenuOption("Registrar nueva persona por la cola", [&] (MenuOptionArguments args) {
        register_person_back();
    }));

    menu_.add_option(MenuOption("Registrar nueva persona por indice", [&] (MenuOptionArguments args) {
        register_person_at();
    }));

    menu_.add_option(MenuOption("Longitud nombre persona", [&] (MenuOptionArguments args) {
        longitud_person(index);
    }));

    menu_.add_option(MenuOption("Cambiar formato nombre", [&] (MenuOptionArguments args) {
        cambiar_letra(index);
    }));

    menu_.add_option(MenuOption("Eliminar persona", [&] (MenuOptionArguments args) {
        delete_person(index);
    }));

    menu_.add_option(MenuOption("Ver personas", [&](MenuOptionArguments args) {
        view_persons();
    }));

    // opcion para regresar al menu principal
    menu_.add_option(MenuOption("Regresar", [this](MenuOptionArguments args) { menu_.stop(); }, false));
}

void PersonsController::run() {
    // show menu
    menu_.display();
}

Person PersonsController::longitud_person(int index){
    if(index == 1){
        return PersonsController::longitud_person(0);
    } else if(index == 2){
        return PersonsController::longitud_person(1);
    }else if(index == 3){
        return PersonsController::longitud_person(2);
    }else if(index == 4){
        return PersonsController::longitud_person(3);
    }else if(index == 5){
        return PersonsController::longitud_person(4);
    }else{
        return PersonsController::longitud_person(5);
    }
}   

void PersonsController::cambiar_letra(int index){
    PersonBuilder persona;
    persona.lastname("Dalton");
    
}

void PersonsController::register_person_front() {
    PersonBuilder person_builder;

    std::string id;
    std::string firstname;
    std::string lastname;
    std::string address;
    std::string phone;

    std::regex name_pattern("^[\\w'\\-,.][^0-9_!�?�?�\\/\\\+=@#$%�&*(){}|~<>;:[\\]]{2,}$");

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        bool exists = (persons_.find([id](Person person) { return person.id() == id; })) != nullptr;

        if (exists) {
            fmt::print(fg(fmt::color::red), "\n[la cedula ya esta registrada]\n");
            continue;
        }

        break;
    } while (true);

    do {
        firstname = read_line("ingrese el nombre: ");

        if (!std::regex_match(firstname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    do {
        lastname = read_line("ingrese el apellido: ");

        if (!std::regex_match(lastname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    address = read_line("ingrese la direccion: ");

    do {
        phone = read_line("ingrese el telefono (+593): ");

        if (!std::regex_match(phone, std::regex("^(09[0-9]{8}|0?[1-8][0-9]{7})$"))) {
            fmt::print(fg(fmt::color::red), "\n[numero incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    Person person = person_builder
        .id(id)
        .firstname(firstname)
        .lastname(lastname)
        .address(address)
        .phone(phone)
        .build();

    std::string email = generateUniqueEmail(persons_, person, "espe.edu.ec");
    person.email(email);

    persons_.push_front(person);
    
    // save person to db 
    save_person(person);
}

void PersonsController::register_person_back() {
    PersonBuilder person_builder;

    std::string id;
    std::string firstname;
    std::string lastname;
    std::string address;
    std::string phone;

    std::regex name_pattern("^[\\w'\\-,.][^0-9_!�?�?�\\/\\\+=@#$%�&*(){}|~<>;:[\\]]{2,}$");

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        bool exists = (persons_.find([id](Person person) { return person.id() == id; })) != nullptr;

        if (exists) {
            fmt::print(fg(fmt::color::red), "\n[la cedula ya esta registrada]\n");
            continue;
        }

        break;
    } while (true);

    do {
        firstname = read_line("ingrese el nombre: ");

        if (!std::regex_match(firstname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    do {
        lastname = read_line("ingrese el apellido: ");

        if (!std::regex_match(lastname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    address = read_line("ingrese la direccion: ");

    do {
        phone = read_line("ingrese el telefono (+593): ");

        if (!std::regex_match(phone, std::regex("^(09[0-9]{8}|0?[1-8][0-9]{7})$"))) {
            fmt::print(fg(fmt::color::red), "\n[numero incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    Person person = person_builder
        .id(id)
        .firstname(firstname)
        .lastname(lastname)
        .address(address)
        .phone(phone)
        .build();

    std::string email = generateUniqueEmail(persons_, person, "espe.edu.ec");
    person.email(email);

    persons_.push_back(person);
    
    // save person to db 
    save_person(person);
}

void PersonsController::register_person_at(){
    int index = 0;
    std::cout << "Ingrese el indice en donde quiere agregar la persona: ";
    std::cin >> index;
    PersonBuilder person_builder;

    std::string id;
    std::string firstname;
    std::string lastname;
    std::string address;
    std::string phone;

    std::regex name_pattern("^[\\w'\\-,.][^0-9_!�?�?�\\/\\\+=@#$%�&*(){}|~<>;:[\\]]{2,}$");

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        bool exists = (persons_.find([id](Person person) { return person.id() == id; })) != nullptr;

        if (exists) {
            fmt::print(fg(fmt::color::red), "\n[la cedula ya esta registrada]\n");
            continue;
        }

        break;
    } while (true);

    do {
        firstname = read_line("ingrese el nombre: ");

        if (!std::regex_match(firstname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    do {
        lastname = read_line("ingrese el apellido: ");

        if (!std::regex_match(lastname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    address = read_line("ingrese la direccion: ");

    do {
        phone = read_line("ingrese el telefono (+593): ");

        if (!std::regex_match(phone, std::regex("^(09[0-9]{8}|0?[1-8][0-9]{7})$"))) {
            fmt::print(fg(fmt::color::red), "\n[numero incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    Person person = person_builder
        .id(id)
        .firstname(firstname)
        .lastname(lastname)
        .address(address)
        .phone(phone)
        .build();

    std::string email = generateUniqueEmail(persons_, person, "espe.edu.ec");
    person.email(email);

    persons_.push_at(person,index);
    
    // save person to db 
    save_person(person);
}

void PersonsController::delete_person(int index){
    std::cout << "Ingrese el numero del indice de la persona que desea borrar" << std::endl;
    cin >> index;
    persons_.remove_at(index);
    std::cout << "Persona eliminada con exito!!!" << std::endl;
}

void PersonsController::save_person(Person person) {
    PersonPojo person_row{person.id(), person.firstname(), person.lastname(), person.address(), person.phone(), person.email()};
    PersonQuery query{make_storage_query()};

    try {
        query.storage.insert(person_row);
    } catch (std::system_error e) {
        std::cout << e.what() << std::endl;
    }
}

void PersonsController::view_persons() {
    std::vector<PersonField> person_fields = {
         PersonField::Id,
         PersonField::Firstname,
         PersonField::Lastname,
         PersonField::Phone,
         PersonField::Email
    };

    std::map<PersonField, std::string> person_field_names = {
        {PersonField::Id, "Cedula"},
        {PersonField::Firstname, "Nombre(s)"},
        {PersonField::Lastname, "Apellido(s)"},
        {PersonField::Phone, "Telefono"},
        {PersonField::Email, "Correo"}
    };

    std::map<PersonField, int> columns_width = {
        {PersonField::Id, person_field_names[PersonField::Id].length()},
        {PersonField::Firstname, person_field_names[PersonField::Firstname].length()},
        {PersonField::Lastname, person_field_names[PersonField::Lastname].length()},
        {PersonField::Phone, person_field_names[PersonField::Phone].length()},
        {PersonField::Email, person_field_names[PersonField::Email].length()}
    };

    // obtener el campo con la longitud mas grande de todas las personas
    persons_.for_each([&](Person person) {
        std::map<PersonField, int> lengths = {
            {PersonField::Id, person.id().length()},
            {PersonField::Firstname, person.firstname().length()},
            {PersonField::Lastname, person.lastname().length()},
            {PersonField::Phone, person.phone().length()},
            {PersonField::Email, person.email().length()}
        };

        for (auto entry : lengths) {
            PersonField field = entry.first;
            int width = entry.second;

            if (lengths[field] > columns_width[field]) {
                columns_width[field] = lengths[field];
            }
        }
    });

    std::cout << "+";

    for (auto entry : columns_width) {
        PersonField field = entry.first;
        std::string pattern = "{:^" + std::to_string(columns_width[field] + 2) + "}";
        std::string formatted = fmt::format(pattern, person_field_names[field]); 
        int width = formatted.length();

        fmt::print("{:-^{}}+", "", width);
    }

    std::cout << std::endl << "|";

    for (auto field : person_fields) {
        std::string pattern = "{:^" + std::to_string(columns_width[field] + 2) + "}";
        fmt::print(pattern, person_field_names[field]);
        fmt::print("|");
    }

    std::cout << std::endl << "+";

    for (auto entry : columns_width) {
        PersonField field = entry.first;
        std::string pattern = "{:^" + std::to_string(columns_width[field] + 2) + "}";
        std::string formatted = fmt::format(pattern, person_field_names[field]);
        int width = formatted.length();

        fmt::print("{:-^{}}+", "", width);
    }

    std::cout << std::endl;

    persons_.for_each([&](Person person) {
        std::map<PersonField, std::string> lengths = {
            {PersonField::Id, person.id()},
            {PersonField::Firstname, person.firstname()},
            {PersonField::Lastname, person.lastname()},
            {PersonField::Phone, person.phone()},
            {PersonField::Email, person.email()}
        };

        std::cout << "|";

        for (auto entry : lengths) {
            PersonField field = entry.first;
            std::string value = entry.second;
            std::string pattern = "{:^" + std::to_string(columns_width[field] + 2) + "}";
            fmt::print(pattern, value);
            fmt::print("|");
        }

        std::cout << std::endl;
    });

    std::cout << "+";

    for (auto entry : columns_width) {
        PersonField field = entry.first;
        std::string pattern = "{:^" + std::to_string(columns_width[field] + 2) + "}";
        std::string formatted = fmt::format(pattern, person_field_names[field]);
        int width = formatted.length();

        fmt::print("{:-^{}}+", "", width);
    }

    std::cout << std::endl;
}

void PersonsController::backup_data() {
    std::ostringstream output;

    persons_.for_each([&output](Person person) {
        output << person.id() << "," << person.firstname() << "," << person.lastname() << "," << person.address()
               << person.phone() << "," << person.email() << std::endl;
    });

    std::ofstream backup("backup.txt", std::ios::trunc);
    backup << output.str();
    backup.close();
}

CircularList<Person> const &PersonsController::get_persons() {
    return persons_;
}
