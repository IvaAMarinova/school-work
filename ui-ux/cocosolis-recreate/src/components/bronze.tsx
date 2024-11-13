import Product from "./product";

function Bronze() {
    const products = [
        {
            badge: "NEW",
            image: "https://cocosolis.com/bg/wp-content/uploads/solis-drops-thumb-500×500.png",
            name: "SOLIS",
            usage: "Self-tanning Face Serum",
            description: "Автобронзиращ серум за лице с хиалуронова киселина. За красив бронзов тен и подмладена кожа.",
            rating: 5,
            reviews: 36,
            price: "56,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/solis-medium-thumb-500x500-min.png",
            name: "SOLIS",
            usage: "Medium Self-tanning Foam",
            description: "Натурална автобронзираща пяна. За наситен и равномерен бронзов тен. Нюанс: Средно наситен",
            rating: 5,
            reviews: 197,
            price: "56,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/solis-dark-thumb-500x500-min.png",
            name: "SOLIS",
            usage: "Dark Self-tanning Foam",
            description: "Натурална автобронзираща пяна. За наситен и равномерен бронзов тен. Нюанс: Тъмен",
            rating: 5,
            reviews: 197,
            price: "56,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/product-solis-instant-thumb-500x500-1.png",
            name: "SOLIS",
            usage: "Instant Weekend Tan",
            description: "Натурална бронзираща пяна с моментален ефект. Постигате безупречен тен за секунди.",
            rating: 5,
            reviews: 63,
            price: "56,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/tanning-mitt-thumb-500x500-min.png",
            name: "SELF-TANNING MITT",
            usage: "For ultimate results",
            description: "За бързо, лесно и безупречно нанасяне на автобронзант.",
            rating: 5,
            reviews: 386,
            price: "22,00 лв."
        },
        {
            badge: "NEW",
            image: "https://cocosolis.com/bg/wp-content/uploads/back-applicator-thumb-500×500-min-shadow.png",
            name: "BACK APPLICATOR",
            usage: "For self-tanning foam",
            description: "За лесно и равномерно нанасяне на автобронзант на гърба.",
            rating: 5,
            reviews: 32,
            price: "28,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/exfoliating-silk-thumb-500x500-min.png",
            name: "EXFOLIATING MITT",
            usage: "100% high quality silk",
            description: "Копринена дълбоко ексфолираща ръкавица. Подходяща за подготовка и премахване на автобронзанта.",
            rating: 5,
            reviews: 88,
            price: "43,00 лв."
        },
        {
            image: "https://cocosolis.com/bg/wp-content/uploads/tanning-brush-thumb-500x500-min.png",
            name: "TANNING BRUSH",
            usage: "Premium tool for face",
            description: "За прецизно и безупречно нанасяне на автобронзант и други продукти.",
            rating: 5,
            reviews: 87,
            price: "48,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-screen min-h-full bg-[#FBF1EB]">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-20">АВТОБРОНЗАНТИ</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                За перфектен тен, без да е необходимо слънце. Постигнете естествено изглеждащ, равномерен, наситен, бронзов тен.
            </p>
            <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 w-screen max-w-5xl px-4 justify-items-center">
                {products.map((product, index) => (
                    <Product
                        key={index}
                        badge={product.badge}
                        image={product.image}
                        name={product.name}
                        usage={product.usage}
                        description={product.description}
                        rating={product.rating}
                        reviews={product.reviews}
                        price={product.price}
                    />
                ))}
            </div>
        </div>
    );
}

export default Bronze;
