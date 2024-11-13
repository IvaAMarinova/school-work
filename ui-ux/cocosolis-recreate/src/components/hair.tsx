import Product from "./product";
import MediaScroll from "../components/media-scroll";

function Hair() {
    const products = [
        {
            badge: "IMPROVED FORMULA",
            award: "https://cocosolis.com/wp-content/uploads/awards-beauty-shortlist-editors-choice.png",
            image: "https://cocosolis.com/bg/wp-content/uploads/grow-thumb-500x500-min-1.png",
            name: "Oil Mask 3in1",
            usage: "GROW",
            description: "Спрей серум за бърз растеж на косата. Намалява косопада. За видимо по-здрава и силна коса.",
            rating: 5,
            reviews: 938,
            price: "59,00 лв."
        },
        {
            award: "https://cocosolis.com/wp-content/uploads/awards-beauty-shortlist-editors-choice.png",
            image: "https://cocosolis.com/bg/wp-content/uploads/hair-thumb-500x500-min.png",
            usage: "HAIR",
            name: "Oil Mask 3in1",
            description: "Натурално масло маска 3в1 за интензивно подхранване, възстановяване и грижа за косата.",
            rating: 5,
            reviews: 568,
            price: "45,00 лв."
        }
    ];

    return (
        <div className="flex flex-col items-center justify-center w-full min-h-full bg-[#FBF1EB]">
            <h2 className="text-4xl mb-2 text-center text-[#816c65] pt-16">КОСА</h2>
            <p className="text-lg text-[#816c65] mb-10 text-center">
                Натурални продукти за силна, здрава и блестяща коса
            </p>

            <div className="flex flex-wrap justify-center gap-10">
                {products.map((product, index) => (
                    <Product
                        key={index}
                        badge={product.badge}
                        award={product.award}
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
            <MediaScroll />
        </div>
    );
}

export default Hair;
