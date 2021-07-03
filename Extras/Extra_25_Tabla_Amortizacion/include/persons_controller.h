#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "controller.h"
#include "menu.h"

enum class PersonField {
    Id,
    Firstname,
    Lastname,
    Address,
    Phone,
    Email
};

using namespace sqlite_orm;

template <typename... Args>
auto make_storage_query() {
    return make_storage("database.sqlite",
        make_table("persons", make_column("id", &PersonPojo::id, sqlite_orm::unique()),
            make_column("firstname", &PersonPojo::firstname), make_column("lastname", &PersonPojo::lastname),
            make_column("address", &PersonPojo::address), make_column("phone", &PersonPojo::phone),
            make_column("email", &PersonPojo::email, sqlite_orm::unique())));
}

typedef struct PersonQuery {
    decltype(make_storage_query()) storage;
};

class PersonsController : public Controller {
public:
    PersonsController(Application *app);
    virtual void init();
    virtual void run();
    void register_person_front();
    void register_person_back();
    void register_person_at();
    void delete_person(int index);
    Person longitud_person(int index);
    void cambiar_letra(int index);
    void save_person(Person person);
    void view_persons();
    void backup_data();
    CircularList<Person> const &get_persons();

private:
    CircularList<Person> persons_;
    Menu menu_;
};
