class Aplicacion {
    public:
        static Aplicacion &get_instance();
        void run();
    
    private:
        Aplicacion() = default;
        Aplicacion(const Aplicacion &) = default;
        void operator=(const Aplicacion &) = delete;
        Aplicacion(Aplicacion &&) noexcept = default;
        Aplicacion &operator=(Aplicacion &&) noexcept = default;

        static Aplicacion *instance;
};
